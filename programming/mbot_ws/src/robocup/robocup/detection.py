import rclpy
from geometry_msgs.msg import Twist
from rclpy.node import Node
from mazebot_msgs.msg import VictimDetected
from mazebot_msgs.msg import Dropper
from std_msgs.msg import Int32
import serial




class SerialDisplayMazebot:
        def __init__(self, baudrate = 9600, port = '/dev/ttyACM0', tout = 0.1):
            self.baudrate = baudrate
            self.port = port
            self.serial = serial.Serial(self.port, baudrate, timeout=tout)

        def victim_found(self):
            xmtMessage = "victim found"
            self.serial.write(xmtMessage.encode('utf-8'))
            

        def blue_tile(self):
            xmtMessage = "blue tile"
            self.serial.write(xmtMessage.encode('utf-8'))

        def end_run(self):
            xmtMessage = "end"
            self.serial.write(xmtMessage.encode('utf-8'))

        def check_start_button(self) -> bool:
            returnmessage = self.serial.readline()
            if returnmessage == "Start pressed":
                return True
            else:
                return False

        def check_restart_button(self) -> bool:
            returnmessage = self.serial.readline()
            if returnmessage == "Restart pressed":
                return True
            else:
                return False
            
class DisplayMazeBot(Node):
    def __init__(self):
        super().__init__('display_mazebot')
        self.publisher_dropper = self.create_publisher(Dropper, 'dropper', 10)
        self.publisher_start = self.create_publisher(Int32, '/naviagtion/start', 10)
        self.publisher_restart = self.create_publisher(Int32, '/naviagtion/restart', 10)
        self.subscription_ = self.create_subscription(VictimDetected, 'letters_detected', self.subscription_letter_callback, 10)
        self.subscription_color = self.create_subscription(VictimDetected, 'colors_detected', self.subscription_color_callback, 10)
        self.buttons
        self.serial = SerialDisplayMazebot()

    def subscription_letter_callback(self, msg):
        self.get_logger().info('Letters detected: "%s"' % msg.victim_id)
        self.serial.victim_found()
        if msg.victim_id == 'H':
            self.publisher_dropper.publish(kits=3, location = msg.victim_location)
        elif msg.victim_id == 'S':
            self.publisher_dropper.publish(kits=1, location = msg.victim_location)
            


    def subscription_color_callback(self, msg):
        self.get_logger().info('Color detected: "%s"' % msg.victim_id)
        self.serial.victim_found()
        if msg.victim_id == 'ROT':
            self.publisher_dropper.publish(kits=1, location = msg.victim_location)
        elif msg.victim_id == 'GELB':
            self.publisher_dropper.publish(kits=1, location = msg.victim_location)

    def buttons(self):
        if self.serial.check_start_button:
            self.publisher_start.publish(Int32(data=1))
        elif self.serial.check_restart_button:
            self.publisher_restart.publish(Int32(data=1))

def main(args=None):

    rclpy.init(args = args)

    display_mazebot = DisplayMazeBot()

    rclpy.spin(display_mazebot)

    display_mazebot.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()