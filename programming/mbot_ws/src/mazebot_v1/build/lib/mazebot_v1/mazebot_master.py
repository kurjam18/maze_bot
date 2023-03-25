import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class MazebotMaster(Node):

    def __init__(self):
        super().__init__('Master node')
        self.subscription = self.create_subscription(
        String,                                               # CHANGE
            'dedectet_letters',
            self.listener_callback,
            10)
        self.publisher_ = self.create_publisher(String, 'cmd_vel', 10)
        self.subscription

    def listener_callback(self, msg):
            self.get_logger().info('I heard: "%d"' % msg.data)  # CHANGE

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1

def main(args=None):
    rclpy.init(args=args)

    subscriber = MazebotMaster()

    rclpy.spin(subscriber)

    subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
