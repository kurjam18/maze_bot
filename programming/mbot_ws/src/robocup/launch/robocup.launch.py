import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import LogInfo
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node



def generate_launch_description():

    package_name='robocup' 
    
    port = LaunchConfiguration('port', default='/dev/ttyUSB0')
    frame_id = LaunchConfiguration('frame_id', default='laser')

    wall_detection = Node(
        package="robocup",
        executable="wall_det",
    )

    detection = Node(
        package="robocup",
        executable="detection",
    )

    mazebot_serial = Node(
        package="robocup",
        executable="serial",
    )

    navigation = Node(
        package="robocup",
        executable="navigation",
    )

    lidar = Node(
        package='hls_lfcd_lds_driver',
        executable='hlds_laser_publisher',
        name='hlds_laser_publisher',
        parameters=[{'port': port, 'frame_id': frame_id}],
        output='screen'
        )

    # Launch them all!
    return LaunchDescription([
        mazebot_serial,
        navigation, 
        wall_detection,
        lidar, 
    ])
