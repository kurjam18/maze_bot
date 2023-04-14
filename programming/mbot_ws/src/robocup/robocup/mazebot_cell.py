import rclpy
from rclpy.node import Node
from rclpy.qos import QoSDurabilityPolicy, QoSHistoryPolicy, QoSReliabilityPolicy
from rclpy.qos import QoSProfile

from enum import IntEnum

from geometry_msgs.msg import Twist
from std_msgs.msg import Int32
from std_msgs.msg import Float32
from std_msgs.msg import Bool
from mazebot_msgs.msg import MazebotFieldOrientation
from mazebot_msgs.msg import MazebotNeighboringFieldsWallDetection
from mazebot_msgs.msg import VictimDetected
from mazebot_msgs.msg import Dropper

import time
import math

class NavigationStates(IntEnum):
    NAV_STATE_START = 0
    NAV_STATE_ALIGMENT = 1
    NAV_STATE_WALLDETECTION = 2
    NAV_STATE_MOVETONEXTCELL = 3
    NAV_STATE_MARKERDETECTION = 4
    NAV_STATE_HOMECOMING = 5
    NAV_STATE_TURN = 6
    NAV_STATE_MOVE = 7
    NAV_STATE_ALIGMENT_A_TURN = 8

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
    MARKER_YELLOW_BLUE = 10

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
    
    def __getNextCellOffset__(self, direction = RobotDirectionDefinition.DIRECTION_FRONT):
        robot_cell_orientation = self.map_path[-1][1]
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
        
        return (dx, dy)

    def moveRobotNextCell(self, direction = RobotDirectionDefinition.DIRECTION_FRONT):
        position, robot_cell_orientation = self.map_path[-1]
        pos_x = position[0]
        pos_y = position[1]

        (dx, dy) = self.__getNextCellOffset__(direction)
        
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
        
    def setWallsOfCurrentCell(self, front=WallDefinition.WALL_UNKNOWN, rear=WallDefinition.WALL_UNKNOWN, left=WallDefinition.WALL_UNKNOWN, right=WallDefinition.WALL_UNKNOWN):
        pos, robot_cell_orientation = self.map_path[-1]
        pos_x = pos[0]
        pos_y = pos[1]

        if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_NORTH] = front
            self.map_cells[pos_x][ pos_y].wall[RobotCellOrientation.CELL_SOUTH] = rear
            self.map_cells[pos_x][ pos_y].wall[RobotCellOrientation.CELL_EAST] = right
            self.map_cells[pos_x][ pos_y].wall[RobotCellOrientation.CELL_WEST] = left
            
        elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_NORTH] = left
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_SOUTH] = right
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_EAST] = front
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_WEST] = rear
    
        elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_NORTH] = rear
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_SOUTH] = front
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_EAST] = left
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_WEST] = right
        else:
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_NORTH] = right
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_SOUTH] = left
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_EAST] = rear
            self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_WEST] = front

    def getWallsOfCurrentCell(self):
        pos, robot_cell_orientation = self.map_path[-1]
        pos_x = pos[0]
        pos_y = pos[1]

        if robot_cell_orientation == RobotCellOrientation.CELL_NORTH:
            front = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_NORTH]
            rear = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_SOUTH]
            right = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_EAST]
            left = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_WEST]
            
        elif robot_cell_orientation == RobotCellOrientation.CELL_EAST:
            left = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_NORTH]
            right = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_SOUTH]
            front = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_EAST]
            rear = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_WEST]
    
        elif robot_cell_orientation == RobotCellOrientation.CELL_SOUTH:
            rear = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_NORTH]
            front = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_SOUTH]
            left = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_EAST]
            right = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_WEST]
        else:
            right = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_NORTH]
            left = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_SOUTH]
            rear = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_EAST]
            front = self.map_cells[pos_x][pos_y].wall[RobotCellOrientation.CELL_WEST]

        return (front, rear, left, right)
    
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
    
    def getVisitCounter(self, direction = RobotDirectionDefinition.DIRECTION_INVALID):
        (dx, dy) = self.__getNextCellOffset__(direction)
        (cell_x, cell_y) = self.map_path[-1][0]
        return self.map_cells[cell_x + dx][cell_y + dy].visit_counter
    
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
        Node.__init__(self,'MazeBotNavigation')
        MazebotMap.__init__(self, 30, 30)
        
        self.map_cell_length = 0.3
        self.lidar_cell_offset = (0.03, 0.0)
        self.distance_max_epsilon = (0.03, 0.03)
        self.tangent_max_epsilon = 5 * (math.pi/180.0)

        self.vel_max_linear = 0.10
        self.vel_max_angular = 20 * (math.pi/180.0)

        self.timer_nav_interval = 2.0 #sec
        self.msg_wall_orientation = None
        self.msg_wall_detection = None
        self.navigation_enabled = True
        self.nav_busy = False
        self.teensy_busy = False
        self.nav_state = NavigationStates.NAV_STATE_START
        self.move_direction = RobotDirectionDefinition.DIRECTION_INVALID

        print("MazeBotNavigation Initialized")


        self.sub_mb_orientation = self.create_subscription(
            MazebotFieldOrientation,
            "/mazebot_wall_detection/orientation",
            self.listener_callback_orientation,
            10)
        
        self.sub_mb_wall_detection = self.create_subscription(
            MazebotNeighboringFieldsWallDetection,
            "/mazebot_wall_detection/detection",
            self.listener_callback_wall_detetion,5)
        
        self.sub_mb_nav_start = self.create_subscription(
            Bool,
            "/naviagtion/start",
            self.listener_callback_navigation_start,5)
        
        self.sub_isbusy = self.create_subscription(
            Bool,
            "/is_busy",
            self.listener_callback_navigation_isbusy,5)
        
        self.pub_cmd_vel = self.create_publisher(Twist, 'cmd_vel', 10)
        self.pub_move = self.create_publisher(Float32, 'move', 10)
        self.pub_turn = self.create_publisher(Float32, 'turn', 10)
        self.timer_nav = self.create_timer(self.timer_nav_interval, self.timer_nav_callback)

        self.publisher_dropper = self.create_publisher(Dropper, 'dropper', 10)
        self.subscription_ = self.create_subscription(VictimDetected, 'letters_detected', self.subscription_letter_callback, 10)
        self.subscription_color = self.create_subscription(VictimDetected, 'colors_detected', self.subscription_color_callback, 10)


    def timer_nav_callback(self):
        if (self.nav_busy == False) and (self.teensy_busy == False):
            self.navigate()

    def navigate(self):
        if (self.msg_wall_detection is not None and self.msg_wall_orientation is not None):
            if (self.navigation_enabled):
                
                if (self.nav_state == NavigationStates.NAV_STATE_START):
                    self.nav_state = NavigationStates.NAV_STATE_ALIGMENT
                    print("Start")

                elif (self.nav_state == NavigationStates.NAV_STATE_ALIGMENT):
                    print("Alligment")
                    if self.alignRobotToCell() == True:
                        self.nav_state = NavigationStates.NAV_STATE_MARKERDETECTION
                        

                elif (self.nav_state == NavigationStates.NAV_STATE_MARKERDETECTION):
                    print("NAV_STATE_MARKERDETECTION")
                    self.nav_state = NavigationStates.NAV_STATE_WALLDETECTION

                    #TODO: elf.setCurrentCellMarker(side = RobotDirectionDefinition.DIRECTION_FRONT, marker = WallMarker.MARKER_YELLOW_BLUE)
                    #TODO: Roboer zurück fahren (auf Karte) und neu ausrichten bei schwarzem Feld!!
                    #TODO: Rechte am I2C-Bus einstellen!
                    # t = time.process_time()
                    # #do some stuffls -l /dev/i2c-1
                    # elapsed_time = time.process_time() - t

                elif (self.nav_state == NavigationStates.NAV_STATE_WALLDETECTION):
                    print("NAV_STATE_WALLDETECTION")
                    self.saveCurrentCellWallsToMap()
                    self.nav_state = NavigationStates.NAV_STATE_MOVETONEXTCELL

                elif (self.nav_state == NavigationStates.NAV_STATE_MOVETONEXTCELL):
                    print("NAV_STATE_MOVETONEXTCELL")
                    self.move_direction = self.moveRobotToNextCell()
                    print(self.move_direction)

                    if (self.move_direction == RobotDirectionDefinition.DIRECTION_FRONT):
                        self.nav_state = NavigationStates.NAV_STATE_MOVE
                    else:
                        self.nav_state = NavigationStates.NAV_STATE_TURN

                elif (self.nav_state == NavigationStates.NAV_STATE_TURN):
                    print("NAV_STATE_TURN")
                    if (self.move_direction == RobotDirectionDefinition.DIRECTION_FRONT):
                        self.nav_state = NavigationStates.NAV_STATE_ALIGMENT_A_TURN
                    else:
                        self.rotateRobotOrientation(direction=RobotDirectionDefinition.DIRECTION_RIGHT)
                        rot_ang = 1.57
                        if (self.move_direction == RobotDirectionDefinition.DIRECTION_RIGHT):
                            self.move_direction = RobotDirectionDefinition.DIRECTION_FRONT
                        elif (self.move_direction == RobotDirectionDefinition.DIRECTION_LEFT):
                            self.move_direction = RobotDirectionDefinition.DIRECTION_FRONT
                            rot_ang = -rot_ang
                        else:
                            self.move_direction = RobotDirectionDefinition.DIRECTION_RIGHT
                        
                        self.pub_turn.publish(Float32(data = rot_ang))
                        self.nav_state = NavigationStates.NAV_STATE_TURN

                elif (self.nav_state == NavigationStates.NAV_STATE_ALIGMENT_A_TURN):
                    print("Alligment")
                    if self.alignRobotToCell() == True:
                        if (self.move_direction == RobotDirectionDefinition.DIRECTION_FRONT):
                            self.nav_state = NavigationStates.NAV_STATE_MOVE
                        else:
                            self.nav_state = NavigationStates.NAV_STATE_TURN

                elif (self.nav_state == NavigationStates.NAV_STATE_MOVE):
                    print("NAV_STATE_MOVE ")
                    self.moveRobotNextCell(direction = RobotDirectionDefinition.DIRECTION_FRONT)
                    self.pub_move.publish(Float32(data=0.3))
                    self.nav_state = NavigationStates.NAV_STATE_ALIGMENT

                elif (self.nav_state == NavigationStates.NAV_STATE_HOMECOMING):
                    self.nav_state = NavigationStates.NAV_STATE_START
                
            else:
                vel = Twist()
                vel.linear.x = 0.0
                vel.linear.y = 0.0
                vel.linear.z = 0.0
                vel.angular.x = 0.0
                vel.angular.y = 0.0
                vel.angular.z = 0.0
                self.pub_cmd_vel.publish(vel)

    def listener_callback_orientation(self, msg):
        # print("orientation")
        self.msg_wall_orientation = msg

    def listener_callback_wall_detetion(self, msg):
        # print("detection")
        self.msg_wall_detection = msg

    def listener_callback_navigation_start(self, msg):
        self.get_logger().info('Nav gestartet')
        print("nav started")
        self.navigation_enabled = bool(msg.data)

    def listener_callback_navigation_isbusy(self, msg):
        self.teensy_busy = bool(msg.data)
        self.nav_busy = self.teensy_busy

    def subscription_letter_callback(self, msg):
        self.get_logger().info('Letters detected: "%s"' % msg.victim_id)
        if msg.victim_id == 'H':
            self.publisher_dropper.publish(kits=3, location = msg.victim_location)
        elif msg.victim_id == 'S':
            self.publisher_dropper.publish(kits=1, location = msg.victim_location)
            
    def subscription_color_callback(self, msg):
        self.get_logger().info('Color detected: "%s"' % msg.victim_id)
        if msg.victim_id == 'ROT':
            self.publisher_dropper.publish(kits=1, location = msg.victim_location)
        elif msg.victim_id == 'GELB':
            self.publisher_dropper.publish(kits=1, location = msg.victim_location)

    def alignRobotToCell(self):
        retval = False

        vel = Twist()
        vel.linear.x = 0.0
        vel.angular.z = 0.0

        dis_error = (self.msg_wall_orientation.front_distance % self.map_cell_length) - (self.map_cell_length/2.0)
        dis_error += self.lidar_cell_offset[0]
        
        print(dis_error, self.msg_wall_orientation.front_distance, self.map_cell_length/2.0, self.lidar_cell_offset[0])

        if (dis_error > self.distance_max_epsilon[0]):
            self.pub_move.publish(Float32(data= dis_error))
        elif (dis_error < -self.distance_max_epsilon[0]):
            self.pub_move.publish(Float32(data= dis_error))
        else: 
            
            angular_err = 0.0
            if (self.msg_wall_orientation.left_distance < 0.0):
                angular_err = self.msg_wall_orientation.right_angle_deg
            elif (self.msg_wall_orientation.right_distance < 0.0):
                angular_err = self.msg_wall_orientation.left_angle_deg
            elif (self.msg_wall_orientation.left_distance < self.msg_wall_orientation.right_distance):
                angular_err = self.msg_wall_orientation.left_angle_deg
            else:
                angular_err = self.msg_wall_orientation.right_angle_deg
            print(angular_err)

            if (self.msg_wall_orientation.left_distance < 0.13):
                angular_err = angular_err + 2.0*(math.pi/180)
            elif (self.msg_wall_orientation.right_distance < 0.13):
                angular_err = angular_err - 2.0*(math.pi/180)

            if ((angular_err > self.tangent_max_epsilon) or (angular_err < -self.tangent_max_epsilon)):
                self.nav_busy=True
                angular_err_rad = (Float32(data=(-angular_err *math.pi /180.0)))
                self.pub_turn.publish(angular_err_rad)

        #     vel.linear.x = 0.0
        #     if (angular_err > self.tangent_max_epsilon):
        #         vel.angular.z = -self.vel_max_angular
        #     elif (angular_err < -self.tangent_max_epsilon):
        #         vel.angular.z = self.vel_max_angular
        #     else:
        #         vel.angular.z = 0.0
        #         retval = True
        # self.pub_cmd_vel.publish(vel)
            retval=True

        return retval

    def saveCurrentCellWallsToMap(self):
        currentw = self.msg_wall_detection.current
        self.setWallsOfCurrentCell(front=currentw[0], rear=currentw[1], left=currentw[2], right=currentw[3])

    def moveRobotToNextCell(self):
        
        direction = RobotDirectionDefinition.DIRECTION_INVALID
        possible_directions = []
        #1.) Wohin kann ich ueberhaupt fahren, Wo sind keine Wände
        (front, rear, left, right) = self.getWallsOfCurrentCell()
        print("Current Cell:", front, rear, left, right)
        if (front == WallDefinition.WALL_NO):
            possible_directions.append([RobotDirectionDefinition.DIRECTION_FRONT])
        if (rear == WallDefinition.WALL_NO):
            possible_directions.append([RobotDirectionDefinition.DIRECTION_REAR])
        if (left == WallDefinition.WALL_NO):
            possible_directions.append([RobotDirectionDefinition.DIRECTION_LEFT])
        if (right == WallDefinition.WALL_NO):
            possible_directions.append([RobotDirectionDefinition.DIRECTION_RIGHT])
    
        print("possible diections:", possible_directions)

        #2.) Welche Zellen wurden davon noch nicht besucht
        for i in range(len(possible_directions)):
            possible_directions[i].append(self.getVisitCounter(possible_directions[i][0])) 
        # Nach der Anzahl von Besuchen sortieren
        for i in range(len(possible_directions)):
            for j in range(len(possible_directions)-1):
                if (possible_directions[j][1]>possible_directions[j+1][1]):
                    save = possible_directions[j]
                    possible_directions[j] = possible_directions[j+1]
                    possible_directions[j+1] = save
        print("possible diections:", possible_directions)

        #3.) Welche Zelle hat von den verbleibenden am meisten Wände
        for i in range(len(possible_directions)):
            if (possible_directions[i][0] == RobotDirectionDefinition.DIRECTION_FRONT):
                possible_directions[i].append(sum(self.msg_wall_detection.front[1:]))
            elif (possible_directions[i][0] == RobotDirectionDefinition.DIRECTION_REAR):
                possible_directions[i].append(sum(self.msg_wall_detection.rear[1:]))
            elif (possible_directions[i][0] == RobotDirectionDefinition.DIRECTION_LEFT):
                possible_directions[i].append(sum(self.msg_wall_detection.left[1:]))
            else:
                possible_directions[i].append(sum(self.msg_wall_detection.right[1:]))
        

        # Nach der Anzahl von Wänden sortieren, am meisten Wände zu Beginn des Arrays
        d_start = 0
        for d in range(len(possible_directions)-1):
            if possible_directions[d+1] != possible_directions[d]:
                for i in range(d_start, d):
                    for j in range(len(possible_directions)-1):
                        if (possible_directions[j][2]<possible_directions[j+1][2]):
                            save = possible_directions[j]
                            possible_directions[j] = possible_directions[j+1]
                            possible_directions[j+1] = save
                d_start = d+1
        print("possible diections:", possible_directions)
        #4.) Bei gleich vielen Wänden nach links fahren
        if (len(possible_directions) == 1): #Zelle mit drei Wände verlassen
            direction = possible_directions[0][0]

        elif possible_directions[0][0] > 0: #Roboter war schon in allen umliegenden Felder!
            #Bevorzuge Links, Geradeaus, Rechts
            for i in range(len(possible_directions)):
                if (possible_directions[i][0]==RobotDirectionDefinition.DIRECTION_LEFT):
                    direction = RobotDirectionDefinition.DIRECTION_LEFT#nach links fahren
                    break
            
            if (direction == RobotDirectionDefinition.DIRECTION_INVALID):
                for i in range(len(possible_directions)):
                    if (possible_directions[i][0]==RobotDirectionDefinition.DIRECTION_FRONT):
                        direction =  RobotDirectionDefinition.DIRECTION_FRONT #nach vorne fahren

            if (direction == RobotDirectionDefinition.DIRECTION_INVALID):
                for i in range(len(possible_directions)):
                    if (possible_directions[i][0]==RobotDirectionDefinition.DIRECTION_RIGHT):
                        direction = RobotDirectionDefinition.DIRECTION_RIGHT #nach rechts fahren
                        break


        elif possible_directions[0][2] == 3: #In die Zelle mit drei Waenden fahren
            direction = possible_directions[0][0]
        else:
            #Bevorzuge Links, Rechts, Geradeaus
            for i in range(len(possible_directions)):
                if (possible_directions[i][0]==RobotDirectionDefinition.DIRECTION_LEFT):
                    direction = RobotDirectionDefinition.DIRECTION_LEFT#nach links fahren
                    break
            if (direction == RobotDirectionDefinition.DIRECTION_INVALID):
                for i in range(len(possible_directions)):
                    if (possible_directions[i][0]==RobotDirectionDefinition.DIRECTION_RIGHT):
                        direction = RobotDirectionDefinition.DIRECTION_RIGHT #nach rechts fahren
                        break
            if (direction == RobotDirectionDefinition.DIRECTION_INVALID):
                for i in range(len(possible_directions)):
                    if (possible_directions[i][0]==RobotDirectionDefinition.DIRECTION_FRONT):
                        direction =  RobotDirectionDefinition.DIRECTION_FRONT #nach vorne fahren

        return direction

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
    possible_directions=[["front", 3], ["rear", 5], ["left", 0], ["right",0]]
    for i in range(len(possible_directions)):
        for j in range(len(possible_directions)-1):
            if (possible_directions[j][1]>possible_directions[j+1][1]):
                save = possible_directions[j]
                possible_directions[j] = possible_directions[j+1]
                possible_directions[j+1] = save
    print(possible_directions)
    # test_main()