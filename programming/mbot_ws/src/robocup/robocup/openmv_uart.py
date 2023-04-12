import serial
import rclpy
from rclpy.node import Node
from std_msgs.msg import String


class OpenMVUart(Node):

    def __init__(self):
        super().__init__('openmv_uart')
        self.publisher_ = self.create_publisher(String, 'letters_detected', 10)
        timer_period = 2.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        
        self.ser = serial.Serial('/dev/ttyACM0', 9600) # Öffnen Sie die UART-Verbindung

    def __del__(self):
        self.ser.close() # Schließen Sie die UART-Verbindung
    
    def timer_callback(self):
        self.read_uart()

    def read_uart(self):
        line = self.ser.readline().decode('utf-8').rstrip()
        if line.startswith('Buchstabe'):
            msg = String()
            msg.data = line
            self.publisher_.publish(msg)
            self.get_logger().info('Publishing: "%s"' % msg.data)


def main(args=None):
    rclpy.init(args=args)

    openmv_uart = OpenMVUart()

    rclpy.spin(openmv_uart)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    openmv_uart.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
