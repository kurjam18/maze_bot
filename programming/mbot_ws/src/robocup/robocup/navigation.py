import rclpy
from geometry_msgs.msg import Twist
from rclpy.node import Node
from mazebot_msgs.msg import VictimDetected
from mazebot_msgs.msg import Dropper
from std_msgs.msg import Int32
from std_msgs.msg import Float32
from mazebot_msgs.msg import MazebotFieldOrientation
from mazebot_msgs.msg import MazebotNeighboringFieldsWallDetection


class DisplayMazeBot(Node):
    def __init__(self):
        super().__init__('display_mazebot')
        self.publisher_dropper = self.create_publisher(Dropper, 'dropper', 10)
        self.publisher_start = self.create_publisher(Int32, '/naviagtion/start', 10)
        self.publisher_restart = self.create_publisher(Int32, '/naviagtion/restart', 10)
        self.cnt = 0

       # self.sub_mb_wall_detection = self.create_subscription(MazebotNeighboringFieldsWallDetection,
       #                                                        "/mazebot_wall_detection/detection",  self.listener_callback_wall_detetion,10)
        
        self.sub_mb_orientation = self.create_subscription(
            MazebotFieldOrientation,
            "/mazebot_wall_detection/orientation",
            self.listener_callback_orientation,
            10)
        
        self.pub_cmd_vel = self.create_publisher(Twist, '/cmd_vel', 10)
        self.pub_turn = self.create_publisher(Float32, '/turn', 10)

    # def listener_callback_wall_detetion(self, msg):
    #     if msg.front_distance > 0.3:
    #         vel = Twist(); 
    #         vel.linear.x = 0.15
    #         self.pub_cmd_vel.publish(vel)

    def listener_callback_orientation(self, msg):
        
        vel = Twist()
        
        if msg.front_distance > 0.3:
            vel.linear.x = 0.10
            self.pub_cmd_vel.publish(vel)
            self.cnt = 0
        elif msg.front_distance <= 0.25:
            vel.linear.x = 0.0
            self.pub_cmd_vel.publish(vel)
            if msg.left_distance > 0.3 and self.cnt == 0:
                self.pub_turn.publish(Float32(data = 1.57))
                self.cnt = 1
            elif msg.right_distance > 0.3:
                self.pub_turn.publish(Float32(data = -1.57))



    def subscription_color_callback(self, msg):
        self.get_logger().info('Color detected: "%s"' % msg.victim_id)
        self.serial.victim_found()
        if msg.victim_id == 'ROT':
            self.publisher_dropper.publish(kits=1, location = msg.victim_location)
        elif msg.victim_id == 'GELB':
            self.publisher_dropper.publish(kits=1, location = msg.victim_location)


def main(args=None):

    rclpy.init(args = args)

    display_mazebot = DisplayMazeBot()

    rclpy.spin(display_mazebot)

    display_mazebot.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()