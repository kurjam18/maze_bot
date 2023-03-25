import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class MotorControll(Node):

    def __init__(self):
        super().__init__('motorcontroller')
        self.subscription = self.create_subscription(
            String,
            'cmd_vel',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)


def main(args=None):
    rclpy.init(args=args)

    motorcontroll_sub = MotorControll()

    rclpy.spin(motorcontroll_sub)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    motorcontroll_sub.destroy_node()
    rclpy.shutdown()




if __name__ == '__main__':
    main()
