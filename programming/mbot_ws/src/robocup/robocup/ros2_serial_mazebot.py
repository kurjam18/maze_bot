import rclpy
from geometry_msgs.msg import Twist
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Int32
import serial




class SerialMazebot:
        def __init__(self, baudrate = 9600, port = '/dev/ttyACM0', tout = 1):
            self.baudrate = baudrate
            self.port = port
            self.serial = serial.Serial(self.port, baudrate, timeout=tout)

        def send_Linear(self, velocity)->String:
            xmtMessage = "vlin:" + "{:.2f}".format(velocity) + "\n"
            self.serial.write(xmtMessage.encode('utf-8'))
            returnmessage = self.serial.readline()

            return returnmessage

        def send_Angular(self, velocity)->String:
            xmtMessage = "vang:" + "{:.2f}".format(velocity) + "\n"
            self.serial.write(xmtMessage.encode('utf-8'))
            returnmessage = self.serial.readline()

            return returnmessage

        def dropKits(self, amount = 0) -> int:
            xmtMessage = "drop:" + "{:d}".format(amount) + "\n"
            self.serial.write(xmtMessage.encode('utf-8'))
            returnmessage = self.serial.readline()

            return int(returnmessage)


class Ros2SerialMazeBot(Node):
    def __init__(self):
        super().__init__('ros2_serial_mazebot')
        self.subscription_cmd_vel = self.create_subscription(
            Twist,
            '/cmd_vel',
            self.listener_callback_cmd_vel,
            10)
        self.subscription_dropper = self.create_subscription(
            Int32,
            '/dropper',
            self.listener_callback_dropper,
            10)
        self.serial = SerialMazebot()

    def listener_callback_cmd_vel(self, msg):
        self.serial.send_Linear(msg.linear.x)
        self.serial.send_Angular(msg.angular.z)
        self.get_logger().info('Linear velocity: %f, Angular velocity: %f' % (msg.linear.x, msg.angular.z))

    def listener_callback_dropper(self, msg):
        self.serial.dropKits(msg.data)
        self.get_logger().info('Dropping %d kits' % msg.data)

def main(args=None):
    rclpy.init(args=args)
    ros2_serial_mazebot = Ros2SerialMazeBot()
    rclpy.spin(ros2_serial_mazebot)
    ros2_serial_mazebot.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()