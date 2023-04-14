import rclpy
from geometry_msgs.msg import Twist
from rclpy.node import Node
from mazebot_msgs.msg import VictimDetected
from mazebot_msgs.msg import Dropper
from std_msgs.msg import Int32
from std_msgs.msg import Bool
import serial




class SerialDisplayMazebot:
    def __init__(self, baudrate=9600, port='/dev/ttyACM0', tout=1.0):
        self.baudrate = baudrate
        self.port = port
        self.serial = serial.Serial(self.port, baudrate, timeout=tout)

    def victim_found(self):
        xmtMessage = "victim found\n"
        self.serial.write(xmtMessage.encode('utf-8'))

    def blue_tile(self):
        xmtMessage = "blue tile\n"
        self.serial.write(xmtMessage.encode('utf-8'))

    def end_run(self):
        xmtMessage = "end\n"
        self.serial.write(xmtMessage.encode('utf-8'))

    def check_start_button(self) -> bool:
        
        if self.serial.in_waiting > 0:
            returnmessage = self.serial.readline().decode('utf-8').strip()
            if returnmessage == "Start pressed":
                print(returnmessage)
                return True
            else:
                return False
        else:
            return False

    def check_restart_button(self) -> bool:
        
        if self.serial.in_waiting > 0:
            returnmessage = self.serial.readline().decode('utf-8').strip()
            if returnmessage == "Restart pressed":
                print(returnmessage)
                return True
            else:
                return False
        else:
            return False

            
class DisplayMazeBot(Node):
    def __init__(self):
        super().__init__('display_mazebot')
        self.serial = SerialDisplayMazebot()
        self.publisher_dropper = self.create_publisher(Dropper, 'dropper', 10)
        self.publisher_start = self.create_publisher(Bool, '/naviagtion/start', 10)
        self.publisher_restart = self.create_publisher(Bool, '/naviagtion/restart', 10)
        self.subscription_ = self.create_subscription(VictimDetected, 'letters_detected', self.subscription_letter_callback, 10)
        self.subscription_color = self.create_subscription(VictimDetected, 'colors_detected', self.subscription_color_callback, 10)
        self.serial.blue_tile()
        timer_period = 1.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        print("timer")
        if self.serial.check_start_button():
            self.publisher_start.publish(Bool(data=True))
            print("Start gedrückt")
        elif self.serial.check_restart_button():
            self.publisher_restart.publish(Bool(data=False))
            print("Stop gedrückt")

    def subscription_letter_callback(self, msg):
        if (msg.victim_id == 'H') or (msg.victim_id == 'S') or (msg.victim_id == 'U') :
            self.publisher_dropper.publish(kits=3, location = msg.victim_location)
            self.publisher_dropper.publish(kits=1, location = msg.victim_location)
            self.get_logger().info('Letters detected: "%s"' % msg.victim_id)
            self.serial.victim_found()

    def subscription_color_callback(self, msg):
        
        self.get_logger().info('Color detected: "%s"' % msg.victim_id)
        self.serial.victim_found()

def main(args=None):

    rclpy.init(args = args)

    display_mazebot = DisplayMazeBot()

    rclpy.spin(display_mazebot)

    display_mazebot.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()