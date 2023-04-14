
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy, QoSHistoryPolicy, QoSReliabilityPolicy
from rclpy.qos import QoSProfile

from sensor_msgs.msg import LaserScan
# from visualization_msgs.msg import MarkerArray, Marker
from mazebot_msgs.msg import MazebotFieldOrientation
from mazebot_msgs.msg import MazebotNeighboringFieldsWallDetection

# import copy
import math
# from math import pi, cos, sin, atan2



class MazeBotWallDetection(Node):
    def __init__(self):
        super().__init__('MazeBotWallDetection')
    
        self.window_size = 2
        self.minimum_distance_laser = 0.10
        # self.maximum_distance_laser = 0.30
        self.field_length = 0.3     # meter

        qos_profile = QoSProfile(depth=10)
        qos_profile.reliability = QoSReliabilityPolicy.BEST_EFFORT
        qos_profile.durability = QoSDurabilityPolicy.VOLATILE


        self.subscription = self.create_subscription(
            LaserScan,
            '/scan',
            self.lidar_callback,
            qos_profile,
        )

        self.mazebot_wall_orientation_publisher = self.create_publisher(MazebotFieldOrientation, "/mazebot_wall_detection/orientation", 1)        
        self.mazebot_wall_detection_publisher = self.create_publisher(MazebotNeighboringFieldsWallDetection, "/mazebot_wall_detection/detection", 1)        


    def get_distance(self, data, index):
      
        distance_sum = 0
        valid_values = 0
        min_index = index - int(self.window_size/2)
        max_index = index + int(self.window_size/2)
        
        for i in range(min_index, max_index):
            if ( i < 0 ):
                i = i + len(data)
                
            if ( i > len(data) ):
                i = i - len(data)
            
            if ( abs(data[i]) > self.minimum_distance_laser ):
                valid_values = valid_values + 1
                distance_sum = distance_sum + data[i]

        if ( valid_values > 0 ):    
            return (distance_sum / valid_values)
        else:
            return -1.0
        
    def get_wall_angle(self, msg):
    
        scan_range = msg.ranges
        angle_min = msg.angle_min
        angle_increment = msg.angle_increment

        # calculate the index position of the distance values (front, rear, left, right) 
        # from the arry with the measurement results
        front_index = int(math.pi / msg.angle_increment)
        rear_index = 0
        right_index = int(((math.pi / 180) * 90) / msg.angle_increment)
        left_index = int(((math.pi / 180) * 270) / msg.angle_increment)

        opening_angle_deg = 10  # opening angle
        opening_angle_index_range = int(((math.pi/180) * opening_angle_deg) / angle_increment / 2)

        # angle of the RIGHT wall
        right_index1 = right_index - opening_angle_index_range
        right_index2 = right_index + opening_angle_index_range
        right_angle = (angle_min + (right_index1 * angle_increment))
        right_distance1 = scan_range[right_index1]
        right_distance2 = scan_range[right_index2]

        dx = math.sin(right_angle) * (right_distance1 - right_distance2)
        dy = math.cos(right_angle) * (right_distance1 + right_distance2)
        
        right_wall_angle = math.atan2(dy, dx)
        if (right_wall_angle > 0):
            right_wall_angle = ((math.pi/180) * 90) - right_wall_angle
        
        
        # angle of the LEFT wall
        left_index1 = left_index - opening_angle_index_range
        left_index2 = left_index + opening_angle_index_range
        left_angle =   2*math.pi - (angle_min + (left_index2 * angle_increment))
        left_distance1 = scan_range[left_index1]
        left_distance2 = scan_range[left_index2]

        
        dx = math.sin(left_angle) * (left_distance1 - left_distance2)
        dy = math.cos(left_angle) * (left_distance1 + left_distance2)
        
        left_wall_angle = math.atan2(dy, dx)
        if (left_wall_angle > 0):
            left_wall_angle = ((math.pi/180) * 90) - left_wall_angle


        # angle of the front wall  TODO Für laser noch anpassen
        front_index1 = front_index - opening_angle_index_range
        if (front_index1 < 0):
            front_index1 = len(scan_range) + front_index1

        front_index2 = front_index + opening_angle_index_range
        if (front_index2 > len(scan_range)):
            front_index2 = front_index2 - len(scan_range)

        front_angle = math.pi/2 - (angle_min + (front_index2 * angle_increment))
        front_distance1 = scan_range[front_index1]
        front_distance2 = scan_range[front_index2]

        dx = math.sin(front_angle) * (front_distance1 - front_distance2)
        dy = math.cos(front_angle) * (front_distance1 + front_distance2)
        
        front_wall_angle = math.atan2(dy, dx)
        if (front_wall_angle > 0):
            front_wall_angle = ((math.pi/180) * 90) - front_wall_angle


        # angle of the rear wall
        rear_index1 = rear_index - opening_angle_index_range
        rear_index2 = rear_index + opening_angle_index_range

        rear_angle = angle_min + (rear_index1 * angle_increment) - math.pi/2
        rear_distance1 = scan_range[rear_index1]
        rear_distance2 = scan_range[rear_index2]

        dx = math.sin(rear_angle) * (rear_distance1 - rear_distance2)
        dy = math.cos(rear_angle) * (rear_distance1 + rear_distance2)
        
        rear_wall_angle = math.atan2(dy, dx)
        if (rear_wall_angle > 0):
            rear_wall_angle = ((math.pi/180) * 90) - rear_wall_angle
        return (front_wall_angle, rear_wall_angle, left_wall_angle, right_wall_angle)
    
    def detect_neighbour_walls(self, msg):
        
        scan_range = msg.ranges
        angle_min = msg.angle_min
        angle_increment = msg.angle_increment

        current_wall_detection = [-1] * 4
        front_wall_detection = [-1] * 4     # [front, rear, left, right], -1... invalid, 0... no wall detected, 1... wall detected
        rear_wall_detection = [-1] * 4      # [front, rear, left, right], -1... invalid, 0... no wall detected, 1... wall detected
        left_wall_detection = [-1] * 4      # [front, rear, left, right], -1... invalid, 0... no wall detected, 1... wall detected
        right_wall_detection = [-1] * 4     # [front, rear, left, right], -1... invalid, 0... no wall detected, 1... wall detected

        side_epsilon = 0.5 * self.field_length * 0.3
        rear_epsilon = 1.5 * self.field_length * 0.3
        front_epsilon = 0.5 * self.field_length * 0.3


        left_wall_angle = 25 * (math.pi/180)
        right_wall_angle = 25 * (math.pi/180)
        front_wall_angle = 0 * (math.pi/180)
        rear_wall_angle = 0 * (math.pi/180)

        #CURRENT-Cell
        front_wall_index = int(math.pi / msg.angle_increment)
        rear_wall_index = 0
        left_wall_index = int(((math.pi / 180) * 270) / msg.angle_increment)
        right_wall_index = int(((math.pi / 180) * 90) / msg.angle_increment)

        distance = self.get_distance(scan_range, front_wall_index)
        if ( distance < (0.5 * self.field_length + front_epsilon) and distance > (0.5 * self.field_length - front_epsilon)):
            current_wall_detection[0] = 1
        else:
            current_wall_detection[0] = 0

        distance = self.get_distance(scan_range, rear_wall_index)
        if ( distance < (0.5 * self.field_length + rear_epsilon) and distance > (0.5 * self.field_length - rear_epsilon)):
            current_wall_detection[1] = 1
        else:
            current_wall_detection[1] = 0

        distance = self.get_distance(scan_range, left_wall_index)
        if ( distance < (0.5 * self.field_length + side_epsilon) and distance > (0.5 * self.field_length - side_epsilon)):
            current_wall_detection[2] = 1
        else:
            current_wall_detection[2] = 0  

        distance = self.get_distance(scan_range, right_wall_index)
        if ( distance < (0.5 * self.field_length + side_epsilon) and distance > (0.5 * self.field_length - side_epsilon)):
            current_wall_detection[3] = 1
        else:
            current_wall_detection[3] = 0


        # front_index = int(math.pi / msg.angle_increment)
        # ear_index = 0
        # left_index = int(((math.pi / 180) * 270) / msg.angle_increment)
        # right_index = int(((math.pi / 180) * 90) / msg.angle_increment)

        # FRONT-Cell
        left_wall_index = int((math.pi + left_wall_angle) / angle_increment)
        right_wall_index = int((math.pi - left_wall_angle) / angle_increment)
        front_wall_index = int(math.pi / msg.angle_increment)
        rear_wall_index = int(math.pi / msg.angle_increment)
    
        distance = (self.get_distance(scan_range, front_wall_index) * math.cos(front_wall_angle))
        if ( distance < (0.5 * self.field_length + front_epsilon) and distance > (0.5 * self.field_length - front_epsilon)):
            front_wall_detection[0] = 1
        else:
            front_wall_detection[0] = 0

            distance = (self.get_distance(scan_range, rear_wall_index) * math.cos(rear_wall_angle))
            if ( distance < (1.5 * self.field_length + rear_epsilon) and distance > (1.5 * self.field_length - rear_epsilon)):
                front_wall_detection[1] = 1
            else:
                front_wall_detection[1] = 0

            distance = (self.get_distance(scan_range, left_wall_index) * math.sin(left_wall_angle))
            if ( distance < (0.5 * self.field_length + side_epsilon) and distance > (0.5 * self.field_length - side_epsilon)):
                front_wall_detection[2] = 1
            else:
                front_wall_detection[2] = 0  

            distance = (self.get_distance(scan_range, right_wall_index) * math.sin(right_wall_angle))
            if ( distance < (0.5 * self.field_length + side_epsilon) and distance > (0.5 * self.field_length - side_epsilon)):
                front_wall_detection[3] = 1
            else:
                front_wall_detection[3] = 0


        # REAR-Cell
        left_wall_index = int((left_wall_angle) / angle_increment)
        right_wall_index = len(scan_range) - int(left_wall_angle / angle_increment)
        front_wall_index = 0
        rear_wall_index = 0
        
        distance = (self.get_distance(scan_range, front_wall_index) * math.cos(front_wall_angle))
        if ( distance < (0.5 * self.field_length + front_epsilon) and distance > (0.5 * self.field_length - front_epsilon)):
            rear_wall_detection[0] = 1
        else:
            rear_wall_detection[0] = 0

            distance = (self.get_distance(scan_range, rear_wall_index) * math.cos(rear_wall_angle))
            if ( distance < (1.5 * self.field_length + rear_epsilon) and distance > (1.5 * self.field_length - rear_epsilon)):
                rear_wall_detection[1] = 1
            else:
                rear_wall_detection[1] = 0

            distance = (self.get_distance(scan_range, left_wall_index) * math.sin(left_wall_angle))
            if ( distance < (0.5 * self.field_length + side_epsilon) and distance > (0.5 * self.field_length - side_epsilon)):
                rear_wall_detection[2] = 1
            else:
                rear_wall_detection[2] = 0  

            distance = (self.get_distance(scan_range, right_wall_index) * math.sin(right_wall_angle))
            if ( distance < (0.5 * self.field_length + side_epsilon) and distance > (0.5 * self.field_length - side_epsilon)):
                rear_wall_detection[3] = 1
            else:
                rear_wall_detection[3] = 0

        # LEFT-Cell
        left_wall_index = int(((math.pi / 180) * 270 + left_wall_angle) / angle_increment)
        right_wall_index = int(((math.pi / 180) * 270 - left_wall_angle) / angle_increment)
        front_wall_index = int(((math.pi / 180) * 270) / angle_increment)
        rear_wall_index = int(((math.pi / 180) * 270 ) / angle_increment)
        
        distance = (self.get_distance(scan_range, front_wall_index) * math.cos(front_wall_angle))
        if ( distance < (0.5 * self.field_length + front_epsilon) and distance > (0.5 * self.field_length - front_epsilon)):
            left_wall_detection[0] = 1
        else:
            left_wall_detection[0] = 0

            distance = (self.get_distance(scan_range, rear_wall_index) * math.cos(rear_wall_angle))
            if ( distance < (1.5 * self.field_length + rear_epsilon) and distance > (1.5 * self.field_length - rear_epsilon)):
                left_wall_detection[1] = 1
            else:
                left_wall_detection[1] = 0

            distance = (self.get_distance(scan_range, left_wall_index) * math.sin(left_wall_angle))
            if ( distance < (0.5 * self.field_length + side_epsilon) and distance > (0.5 * self.field_length - side_epsilon)):
                left_wall_detection[2] = 1
            else:
                left_wall_detection[2] = 0  

            distance = (self.get_distance(scan_range, right_wall_index) * math.sin(right_wall_angle))
            if ( distance < (0.5 * self.field_length + side_epsilon) and distance > (0.5 * self.field_length - side_epsilon)):
                left_wall_detection[3] = 1
            else:
                left_wall_detection[3] = 0
            

        # RIGHT-Cell
        left_wall_index = int(((math.pi / 180) * 90 + left_wall_angle) / angle_increment)
        right_wall_index = int(((math.pi / 180) * 90 - left_wall_angle) / angle_increment)
        front_wall_index = int(((math.pi / 180) * 90 ) / angle_increment)
        rear_wall_index = int(((math.pi / 180) * 90) / angle_increment)
        
        distance = (self.get_distance(scan_range, front_wall_index) * math.cos(front_wall_angle))
        if ( distance < (0.5 * self.field_length + front_epsilon) and distance > (0.5 * self.field_length - front_epsilon)):
            right_wall_detection[0] = 1
        else:
            right_wall_detection[0] = 0

            distance = (self.get_distance(scan_range, rear_wall_index) * math.cos(rear_wall_angle))
            if ( distance < (1.5 * self.field_length + rear_epsilon) and distance > (1.5 * self.field_length - rear_epsilon)):
                right_wall_detection[1] = 1
            else:
                right_wall_detection[1] = 0

            distance = (self.get_distance(scan_range, left_wall_index) * math.sin(left_wall_angle))
            if ( distance < (0.5 * self.field_length + side_epsilon) and distance > (0.5 * self.field_length - side_epsilon)):
                right_wall_detection[2] = 1
            else:
                right_wall_detection[2] = 0  

            distance = (self.get_distance(scan_range, right_wall_index) * math.sin(right_wall_angle))
            if ( distance < (0.5 * self.field_length + side_epsilon) and distance > (0.5 * self.field_length - side_epsilon)):
                right_wall_detection[3] = 1
            else:
                right_wall_detection[3] = 0

        return (current_wall_detection, front_wall_detection, rear_wall_detection, left_wall_detection, right_wall_detection)
    
    def lidar_callback(self,msg):

        mazebot_field_orientation = MazebotFieldOrientation()
        mazebot_field_orientation.laser_scan = msg
        mazebot_field_orientation.header = msg.header
        
        rear_index = 0
        front_index = int(math.pi / msg.angle_increment)
        right_index = int(((math.pi / 180) * 90) / msg.angle_increment)
        left_index = int(((math.pi / 180) * 270) / msg.angle_increment)

        print("---------------------------")
        print("scan len: ", len(msg.ranges))
        print("angle_min: ", msg.angle_min)
        print("angle_increment: ", msg.angle_increment)
        print("front_index: ", front_index)
        print("rear_index: ", rear_index)
        print("left_index: ", left_index)
        print("right_index: ", right_index)


        mazebot_field_orientation.front_distance = self.get_distance(msg.ranges, front_index)
        mazebot_field_orientation.rear_distance = self.get_distance(msg.ranges, rear_index)
        mazebot_field_orientation.left_distance = self.get_distance(msg.ranges, left_index)
        mazebot_field_orientation.right_distance = self.get_distance(msg.ranges, right_index)     

        [front_wall_angle, rear_wall_angle, left_wall_angle, right_wall_angle] = self.get_wall_angle(msg)
        mazebot_field_orientation.front_angle_deg = front_wall_angle * 180 / math.pi   
        mazebot_field_orientation.rear_angle_deg = rear_wall_angle * 180 / math.pi   
        mazebot_field_orientation.left_angle_deg = left_wall_angle * 180 / math.pi
        mazebot_field_orientation.right_angle_deg = right_wall_angle * 180 / math.pi      
        
        print("CURRENT FIELD:")
        print("Front: distance=%.2f" % mazebot_field_orientation.front_distance, "tangent=%.2f" % mazebot_field_orientation.front_angle_deg)
        print("Rear:  distance=%.2f" % mazebot_field_orientation.rear_distance,  "tangent=%.2f" % mazebot_field_orientation.rear_angle_deg)
        print("Left:  distance=%.2f" % mazebot_field_orientation.left_distance,  "tangent=%.2f" % mazebot_field_orientation.left_angle_deg)
        print("Right: distance=%.2f" % mazebot_field_orientation.right_distance, "tangent=%.2f" % mazebot_field_orientation.right_angle_deg)     

        mazebot_wall_detection = MazebotNeighboringFieldsWallDetection()
        wall_detection = self.detect_neighbour_walls(msg)

        mazebot_wall_detection.current = wall_detection[0]
        mazebot_wall_detection.front = wall_detection[1]
        mazebot_wall_detection.rear = wall_detection[2]
        mazebot_wall_detection.left = wall_detection[3]
        mazebot_wall_detection.right = wall_detection[4]

        print ("NEIGHBORING FIELDS:")
        print ("Front field walls: ", mazebot_wall_detection.front)
        print ("rear field walls:  ", mazebot_wall_detection.rear)
        print ("left field walls:  ", mazebot_wall_detection.left)
        print ("right field walls: ", mazebot_wall_detection.right)

        self.mazebot_wall_orientation_publisher.publish(mazebot_field_orientation)
        self.mazebot_wall_detection_publisher.publish(mazebot_wall_detection)
   
     
def main(args=None):
    rclpy.init()
    mazebot_wd = MazeBotWallDetection()                  
    rclpy.spin(mazebot_wd)
    mazebot_wd.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
    
