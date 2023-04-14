import rclpy
from geometry_msgs.msg import Twist
from rclpy.node import Node
from std_msgs.msg import String
from std_msgs.msg import Int32
from std_msgs.msg import Float32
from std_msgs.msg import Bool
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

        def dropLeft(self, amount = 0) -> int:
            xmtMessage = "left:" + "{:d}".format(amount) + "\n"
            self.serial.write(xmtMessage.encode('utf-8'))
            returnmessage = self.serial.readline()

            return int(returnmessage)

        def dropRight(self, amount = 0) -> int:
            xmtMessage = "right" + "{:d}".format(amount) + "\n"
            self.serial.write(xmtMessage.encode('utf-8'))
            returnmessage = self.serial.readline()

            return int(returnmessage)

        def stop(self):
            xmtMessage = "stop:\n"
            self.serial.write(xmtMessage.encode('utf-8'))

        def move(self, distance = 0):
            xmtMessage = "move:" + "{:.2f}".format(distance) + "\n"
            self.serial.write(xmtMessage.encode('utf-8'))

            #positiv angle means a right turn, negative angle a left turn
        def turn(self, angle = 0):
            xmtMessage = "turn:" + "{:.2f}".format(angle) + "\n"
            self.serial.write(xmtMessage.encode('utf-8'))

        def isBusy(self)-> bool:
            xmtMessage = "busy:\n"
            self.serial.write(xmtMessage.encode('utf-8'))
            rcvMessage = self.serial.readline().decode('utf-8').strip()
            print(rcvMessage)
            if rcvMessage == "true":
                return True
            else:
                return False


class Ros2SerialMazeBot(Node):
    def __init__(self):
        super().__init__('ros2_serial_mazebot')
        self.subscription_cmd_vel = self.create_subscription(
            Twist,
            '/cmd_vel',
            self.listener_callback_cmd_vel,
            10)
        
        self.subscription_turn = self.create_subscription(
            Float32,
            '/turn',
            self.listener_callback_turn,
            10)
        
        self.subscription_move = self.create_subscription(
            Float32,
            '/move',
            self.listener_callback_move,
            10)
        
        self.subscription_dropper = self.create_subscription(
            Int32,
            '/dropper',
            self.listener_callback_dropper,
            10)
        self.serial = SerialMazebot()
        timer_period = 1.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.pub_isbusy = self.create_publisher(Bool, 'is_busy', 10)

    def timer_callback(self):
        if self.serial.isBusy():
            self. pub_isbusy.publish(Bool(data=True))
            print("isbusy")
        else:
            self. pub_isbusy.publish(Bool(data=False))

    def listener_callback_cmd_vel(self, msg):
        self.serial.send_Linear(msg.linear.x)
        self.serial.send_Angular(msg.angular.z)
        self.get_logger().info('Linear velocity: %f, Angular velocity: %f' % (msg.linear.x, msg.angular.z))

    def listener_callback_turn(self, msg):
        self.serial.turn(msg.data)
        self.get_logger().info('turn')

    def listener_callback_move(self, msg):
        self.serial.move(msg.data)
        self.get_logger().info('move')

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