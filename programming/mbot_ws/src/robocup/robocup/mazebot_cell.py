import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy, QoSHistoryPolicy, QoSReliabilityPolicy
from rclpy.qos import QoSProfile

from enum import IntEnum

from geometry_msgs.msg import Twist
from std_msgs.msg import Int32
from mazebot_msgs.msg import MazebotFieldOrientation
from mazebot_msgs.msg import MazebotNeighboringFieldsWallDetection

import time

class WallMarker(IntEnum):
    MARKER_NONE = 0
    MARKER_COLOR_RED = 1
    MARKER_COLOR_GREEN = 2
    MARKER_COLOR_YELLOW = 3
    MARKER_CHAR_H = 4
    MARKER_CHAR_S = 5
    MARKER_CHAR_U = 6
    MARKER_TEMP = 7
    MARKER_CHECKPOINT = 8
    MARKER_COLOR_BLACK = 9

class WallDefinition(IntEnum):
    WALL_UNKNOWN = -1
    WALL_NO = 0
    WALL_DETECTED = 1


class RobotDirectionDefinition(IntEnum):
    DIRECTION_INVALID = -1
    DIRECTION_FRONT = 0
    DIRECTION_REAR = 1
    DIRECTION_LEFT = 2
    DIRECTION_RIGHT = 3

class RobotCellOrientation(IntEnum):
    CELL_INVALID = -1
    CELL_NORTH = 0
    CELL_SOUTH = 1
    CELL_EAST = 2
    CELL_WEST = 3
    

class MazebotCell:
    def __init__(self, wall=[WallDefinition.WALL_UNKNOWN]*5, wall_marker=[WallMarker.MARKER_NONE]*5, visit_counter = 0, position_x = 0, position_y = 0):
        self.wall = wall
        self.wall_marker = wall_marker
        self.visit_counter = visit_counter
        self.position = (position_x, position_y)

class MazebotMap:
    def __init__(self, map_size_x, map_size_y):
        self.map_cell_length = 0.3
        self.map_size = (map_size_x, map_size_y)
        self.map_cells = self.__create_grid__(map_size_x, map_size_y)
        self.map_offset = (int(map_size_x/2), int(map_size_y/2))
        
        self.map_path = [[self.map_offset, RobotCellOrientation.CELL_NORTH]]
        self.map_cells[self.map_offset[0]][self.map_offset[1]].visit_counter = 1

    def __create_grid__(self, size_x, size_y):
        # Create grid of cells
        map = []
        for i in range(0, size_x):
            row = []
            for j in range(0, size_y):
                cell = MazebotCell(position_x = i, position_y = j)
                row.append(cell)
            map.append(row)
        return map
    
    def moveRobotNextCell(self, direction = RobotDirectionDefinition.DIRECTION_FRONT):
        position, robot_cell_orientation = self.map_path[-1]
        pos_x = position[0]
        pos_y = position[1]

        dx = 0
        dy = 0

        if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
            if direction == RobotDirectionDefinition.DIRECTION_FRONT:
                dy = 1
            elif direction == RobotDirectionDefinition.DIRECTION_REAR:
                dy = -1
            elif direction == RobotDirectionDefinition.DIRECTION_LEFT:
                dx = -1
            else:
                dx = 1
            
        elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
            if direction == RobotDirectionDefinition.DIRECTION_FRONT:
                dx = 1
            elif direction == RobotDirectionDefinition.DIRECTION_REAR:
                dx = -1
            elif direction == RobotDirectionDefinition.DIRECTION_LEFT:
                dy = 1
            else:
                dy = -1
    
        elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
            if direction == RobotDirectionDefinition.DIRECTION_FRONT:
                dy = -1
            elif direction == RobotDirectionDefinition.DIRECTION_REAR:
                dy = 1
            elif direction == RobotDirectionDefinition.DIRECTION_LEFT:
                dx = 1
            else:
                dx = -1
        else:
            if direction == RobotDirectionDefinition.DIRECTION_FRONT:
                dx = -1
            elif direction == RobotDirectionDefinition.DIRECTION_REAR:
                dx = 1
            elif direction == RobotDirectionDefinition.DIRECTION_LEFT:
                dy = -1
            else:
                dy = 1
        
        if dy > 0:
            robot_cell_orientation = RobotCellOrientation.CELL_NORTH
        elif dy < 0:
            robot_cell_orientation = RobotCellOrientation.CELL_SOUTH
        
        if dx > 0:
            robot_cell_orientation = RobotCellOrientation.CELL_EAST
        elif dx < 0:
            robot_cell_orientation = RobotCellOrientation.CELL_WEST

        #neue zelle im pfad einfuegen
        self.map_path.append([(pos_x + dx, pos_y + dy), robot_cell_orientation])

        #visit counter erhoehen
        self.map_cells[pos_x + dx][pos_y + dy].visit_counter =  self.map_cells[pos_x + dx][pos_y + dy].visit_counter + 1
        
    def setWallOfCurrentCell(self, front=WallDefinition.WALL_UNKNOWN, rear=WallDefinition.WALL_UNKNOWN, left=WallDefinition.WALL_UNKNOWN, right=WallDefinition.WALL_UNKNOWN):
        pos, robot_cell_orientation = self.map_path[-1]
        pos_x = pos[0]
        pos_y = pos[1]

        if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_NORTH] = front
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_SOUTH] = rear
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_EAST] = right
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_WEST] = left
            
        elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_NORTH] = left
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_SOUTH] = right
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_EAST] = front
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_WEST] = rear
    
        elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_NORTH] = rear
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_SOUTH] = front
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_EAST] = left
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_WEST] = right
        else:
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_NORTH] = right
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_SOUTH] = left
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_EAST] = rear
            self.map_cells[pos_x, pos_y].walls[RobotCellOrientation.CELL_WEST] = front


    def rotateRobotOrientation(self, direction = RobotDirectionDefinition.DIRECTION_RIGHT):
        pos, robot_cell_orientation = self.map_path[-1]

        if direction == RobotDirectionDefinition.DIRECTION_RIGHT:
            if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
                orientation = RobotCellOrientation.CELL_EAST
            elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
                orientation = RobotCellOrientation.CELL_SOUTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
                orientation = RobotCellOrientation.CELL_WEST
            elif robot_cell_orientation == RobotCellOrientation.CELL_WEST:
                orientation = RobotCellOrientation.CELL_NORTH

        elif direction == RobotDirectionDefinition.DIRECTION_LEFT:
            if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
                orientation = RobotCellOrientation.CELL_WEST
            elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
                orientation = RobotCellOrientation.CELL_NORTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
                orientation = RobotCellOrientation.CELL_EAST
            elif robot_cell_orientation == RobotCellOrientation.CELL_WEST:
                orientation = RobotCellOrientation.CELL_SOUTH

        elif direction == RobotDirectionDefinition.DIRECTION_REAR:
            if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
                orientation = RobotCellOrientation.CELL_SOUTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
                orientation = RobotCellOrientation.CELL_WEST
            elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
                orientation = RobotCellOrientation.CELL_NORTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_WEST:
                orientation = RobotCellOrientation.CELL_EAST

        self.map_path[-1][1] = orientation

    def setCurrentCellMarker(self, side=RobotDirectionDefinition.DIRECTION_INVALID, marker=WallMarker.MARKER_NONE):
        pos, robot_cell_orientation = self.map_path[-1]
        pos_x = pos[0]
        pos_y = pos[1]

        if side == RobotDirectionDefinition.DIRECTION_FRONT:
            marker_cell_orientation = robot_cell_orientation
        elif side == RobotDirectionDefinition.DIRECTION_LEFT:
            if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
                marker_cell_orientation = RobotCellOrientation.CELL_WEST
            elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
                marker_cell_orientation = RobotCellOrientation.CELL_NORTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
                marker_cell_orientation = RobotCellOrientation.CELL_EAST
            elif robot_cell_orientation == RobotCellOrientation.CELL_WEST:
                marker_cell_orientation = RobotCellOrientation.CELL_SOUTH
    
        elif side == RobotDirectionDefinition.DIRECTION_RIGHT:
            if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
                marker_cell_orientation = RobotCellOrientation.CELL_EAST
            elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
                marker_cell_orientation = RobotCellOrientation.CELL_SOUTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
                marker_cell_orientation = RobotCellOrientation.CELL_WEST
            elif robot_cell_orientation == RobotCellOrientation.CELL_WEST:
                marker_cell_orientation = RobotCellOrientation.CELL_NORTH
        
        elif side == RobotDirectionDefinition.DIRECTION_REAR:
            if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
                marker_cell_orientation = RobotCellOrientation.CELL_SOUTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
                marker_cell_orientation = RobotCellOrientation.CELL_WEST
            elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
                marker_cell_orientation = RobotCellOrientation.CELL_NORTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_WEST:
                marker_cell_orientation = RobotCellOrientation.CELL_EAST
        
        self.map_cells[pos_x][pos_y].wall_marker[marker_cell_orientation] = marker

    def getCurrentCellMarker(self, side=RobotDirectionDefinition.DIRECTION_INVALID):
        pos, robot_cell_orientation = self.map_path[-1]
        pos_x = pos[0]
        pos_y = pos[1]

        if side == RobotDirectionDefinition.DIRECTION_FRONT:
            marker_cell_orientation = robot_cell_orientation
        elif side == RobotDirectionDefinition.DIRECTION_LEFT:
            if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
                marker_cell_orientation = RobotCellOrientation.CELL_WEST
            elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
                marker_cell_orientation = RobotCellOrientation.CELL_NORTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
                marker_cell_orientation = RobotCellOrientation.CELL_EAST
            elif robot_cell_orientation == RobotCellOrientation.CELL_WEST:
                marker_cell_orientation = RobotCellOrientation.CELL_SOUTH
    
        elif side == RobotDirectionDefinition.DIRECTION_RIGHT:
            if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
                marker_cell_orientation = RobotCellOrientation.CELL_EAST
            elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
                marker_cell_orientation = RobotCellOrientation.CELL_SOUTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
                marker_cell_orientation = RobotCellOrientation.CELL_WEST
            elif robot_cell_orientation == RobotCellOrientation.CELL_WEST:
                marker_cell_orientation = RobotCellOrientation.CELL_NORTH
        
        elif side == RobotDirectionDefinition.DIRECTION_REAR:
            if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
                marker_cell_orientation = RobotCellOrientation.CELL_SOUTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
                marker_cell_orientation = RobotCellOrientation.CELL_WEST
            elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
                marker_cell_orientation = RobotCellOrientation.CELL_NORTH
            elif robot_cell_orientation == RobotCellOrientation.CELL_WEST:
                marker_cell_orientation = RobotCellOrientation.CELL_EAST
        else:
            return WallMarker.MARKER_NONE

        return self.map_cells[pos_x][pos_y].wall_marker[marker_cell_orientation]
    

    def printCellInfo(self, x, y):
        cell = self.map_cells[x][y]
        print("Cell(%d,%d):" % (x, y))
        print("Marker [N, S, E, W, F]: ", cell.wall_marker)
        print("Walls [N, S, E, W, F]: ", cell.wall)
        print("Visit Counter: ", cell.visit_counter)

    def printCurrentCellInfo(self):
        # print(self.map_path[-1])
        self.printCellInfo(self.map_path[-1][0][0], self.map_path[-1][0][1])
        print("Robot:", self.map_path[-1][1])

    def __str__(self):
        print_msg = ""
        for i in range(self.map_size[0]): #X-Coord.
            for j in range(self.map_size[1]): #Y-Coord.
                cell = self.map_cells[i][j]
                print_msg += "Cell positions (%02d,%02d):\t[%02d][%02d]\n" % (i, j, cell.position[0], cell.position[1])
                # print("Cell positions (%02d,%02d):\t[%02d][%02d]" % (i, j, cell.position[0], cell.position[1]))
        return print_msg

    def __repr__(self):
        return "MazebotMap(%d x %d)" % (self.map_size[0], self.map_size[1])


class MazeBotNavigation(Node, MazebotMap):
    def __init__(self):
        Node.__init__(self,'navigation')
        MazebotMap.__init__(self, 30, 30)
        
        self.msg_wall_orientation = None
        self.msg_wall_detetion = None
        self.navigation_enabled = False
        self.nav_busy = False


        self.sub_mb_orientation = self.create_subscription(
            MazebotFieldOrientation,
            "/mazebot_wall_detection/orientation",
            self.listener_callback_orientation,
            10)
        
        self.sub_mb_wall_detection = self.create_subscription(
            MazebotNeighboringFieldsWallDetection,
            "/mazebot_wall_detection/detection",
            self.listener_callback_wall_detetion,10)
        
        self.sub_mb_nav_start = self.create_subscription(
            Int32,
            "/navigation/start",
            self.listener_callback_navigation_start,10)
        
        self.pub_cmd_vel = self.create_publisher(Twist, 'cmd_vel', 10)
        self.timer_nav = self.create_timer(1.0, self.timer_nav_callback)


    def timer_nav_callback(self):
        if self.nav_busy == False:
            self.navigate()

    def navigate(self):
        self.nav_busy = True
        if (self.msg_wall_detetion is not None and self.msg_wall_detetion is not None):
            if (self.navigation_enabled):
                self.alignRobotToCell()
                self.moveRobotToNextCell()
            else:
                vel = Twist()
                vel.linear.x = 0.0
                vel.linear.y = 0.0
                vel.linear.z = 0.0
                vel.angular.x = 0.0
                vel.angular.y = 0.0
                vel.angular.z = 0.0
                self.pub_cmd_vel.publish(vel)
        self.nav_busy = False


    def listener_callback_orientation(self, msg):
        self.msg_wall_orientation = msg

    def listener_callback_wall_detetion(self, msg):
        self.msg_wall_detection = msg

    def listener_callback_navigation_start(self, msg):
        self.navigation_enabled = bool(msg.data)

    def alignRobotToCell(self):

        # float32 front_angle_deg        # [grad]
        # float32 rear_angle_deg         # [grad]
        # float32 left_angle_deg         # [grad]
        # float32 right_angle_deg        # [grad]
        dis_misaligned = (self.msg_wall_orientation.front_distance % self.map_cell_length) - (self.map_cell_length/2.0)
        vel = Twist()
        vel.linear.x = 0.15
        vel.angular.z = 0.0
        if (dis_misaligned > 0.02):
            t = vel.linear.x / dis_misaligned
            self.pub_cmd_vel(vel)
            time.sleep(t)
            vel.linear.x = 0.0
            self.pub_cmd_vel(vel)
        elif (dis_misaligned < 0.02):
            t =  vel.linear.x / -dis_misaligned
            vel.linear.x = - vel.linear.x
            self.pub_cmd_vel(vel)
            time.sleep(t)
            vel.linear.x = 0.0
            self.pub_cmd_vel(vel)

        angular = 0.0
        if (self.msg_wall_orientation.left_distance < 0):
            angular = self.msg_wall_orientation.right_angle_deg
        elif (self.msg_wall_orientation.rigth_distance < 0):
            angular = self.msg_wall_orientation.left_angle_deg
        elif (self.msg_wall_orientation.left_distance < self.msg_wall_orientation.right_distance):
            angular = self.msg_wall_orientation.left_angle_deg
        else:
            angular = self.msg_wall_orientation.righ_angle_deg
        

        vel.linear.x = 0.0
        vel.angular.z = 1.0 #rad/s
        if (angular > 3):
            t = vel.angular.z / angular
            self.pub_cmd_vel(vel)
            time.sleep(t)
            vel.angular.z = 0.0
            self.pub_cmd_vel(vel)
        elif (angular < 3):
            t = vel.angular.z / -angular
            vel.angular.z = - vel.angular.z 
            self.pub_cmd_vel(vel)
            time.sleep(t)
            vel.angular.z = 0.0
            self.pub_cmd_vel(vel)

    def moveRobotToNextCell(self):
        pass

    def moveRobotToFrontCell(self):
        pass

    def moveRobotToRearCell(self):
        pass

    def moveRobotToLeftCell():
        pass

    def moveRobotToLeftCell():
        pass



def main(args=None):
    rclpy.init()
    mazebot_nav = MazeBotNavigation()                  
    rclpy.spin(mazebot_nav)
    mazebot_nav.destroy_node()
    rclpy.shutdown()

def test_main(args=None):
    map = MazebotMap(30, 30)
    # print(map)
    map.printCurrentCellInfo()
    map.rotateRobotOrientation(RobotDirectionDefinition.DIRECTION_REAR)
    map.setCurrentCellMarker(RobotDirectionDefinition.DIRECTION_LEFT, WallMarker.MARKER_COLOR_GREEN)
    map.setCurrentCellMarker(RobotDirectionDefinition.DIRECTION_RIGHT, WallMarker.MARKER_COLOR_RED)
    map.printCurrentCellInfo()
    print(map.getCurrentCellMarker(RobotDirectionDefinition.DIRECTION_LEFT))

    map.moveRobotNextCell(RobotDirectionDefinition.DIRECTION_RIGHT)
    map.printCurrentCellInfo()


if __name__ == '__main__':
    test_main()