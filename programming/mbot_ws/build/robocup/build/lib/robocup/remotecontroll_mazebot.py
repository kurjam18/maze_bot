import rclpy
import tty
import sys
import select

from geometry_msgs.msg import Twist
from rclpy.qos import QoSProfile
from std_msgs.msg import Int32

msg = """
Excercise:  RemoteCtrl
Group:      1
Date:       13.10.2022
"""

e = """
Communications Failed
"""

#Pfeil rechts, Pfeil links, Pfeil rauf, Pfeil runter
key_ctrl = ['C', 'D', 'A', 'B']

MAX_LIN_VEL = 0.22          #m/s
MAX_ANG_VEL = 2.84          #rad/s

LIN_VEL_STEP_SIZE = 0.01    #m/s
ANG_VEL_STEP_SIZE = 0.1     #rad/s

def get_key():
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        return sys.stdin.read(1)
    return ''

def main():
    key_null_entered = False

    rclpy.init()

    qos = QoSProfile(depth=10)
    node = rclpy.create_node('remotectrl')
    
    pub = node.create_publisher(Twist, 'cmd_vel', qos)
    pub_dropper = node.create_publisher(Int32, 'dropper', qos)
    
    vel = Twist()
    try:
        print(msg)
        while(1):
            key = get_key()
            if key == '\x03': #Key: STRG+C
                vel.linear.x = 0.0
                vel.angular.z = 0.0
                pub.publish(vel)
                break
            elif key == 'm': #Key: m to stop the robot 
                print("Stop")
                vel.linear.x = 0.0
                vel.angular.z = 0.0
                pub.publish(vel)
            elif key == 't': #Key: m to stop the robot 
                print("Drop")
                kits = 1
                pub_dropper.publish(Int32(data=kits))
            elif key:
                if key == key_ctrl[0]: #Roboter beschleunigt Drehung um Z-Achse
                    print("Right")
                    vel.angular.z = vel.angular.z - ANG_VEL_STEP_SIZE
                    if (vel.angular.z < -MAX_ANG_VEL):
                        vel.angular.z = -MAX_ANG_VEL
                elif key == key_ctrl[1]:
                    print("Left")
                    vel.angular.z = vel.angular.z + ANG_VEL_STEP_SIZE
                    if (vel.angular.z > MAX_ANG_VEL):
                        vel.angular.z = MAX_ANG_VEL
                elif key == key_ctrl[2]:    #Roboter beschleunigt in X-Richtung
                    print("Up")
                    vel.linear.x = vel.linear.x + LIN_VEL_STEP_SIZE
                    if (vel.linear.x > MAX_LIN_VEL):
                        vel.linear.x = MAX_LIN_VEL
                elif key == key_ctrl[3]:    #Robter bremst in X-Richtung
                    print("Down")
                    vel.linear.x = vel.linear.x - LIN_VEL_STEP_SIZE
                    if (vel.linear.x < -MAX_LIN_VEL):
                        vel.linear.x = -MAX_LIN_VEL
            
            pub.publish(vel)
    except Exception as e:
        print(e)

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()