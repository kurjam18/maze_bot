import rclpy
from geometry_msgs.msg import Twist
from rclpy.node import Node
from std_msgs.msg import String
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
        self.subscription = self.create_subscription(
            Twist,
            '/cmd_vel',
            self.listener_callback,
            10)
        self.serial_mazebot = SerialMazebot()

    def listener_callback(self, msg):
        self.serial_mazebot.send_Linear(msg.linear.x)
        self.serial_mazebot.send_Angular(msg.angular.z)
        self.get_logger().info('Linear velocity: %f, Angular velocity: %f' % (msg.linear.x, msg.angular.z))


def main(args=None):
    rclpy.init(args=args)

    ros2_serial_mazebot = Ros2SerialMazeBot()

    rclpy.spin(ros2_serial_mazebot)
    ros2_serial_mazebot.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()


