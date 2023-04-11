from setuptools import setup

package_name = 'robocup'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='kurzmann',
    maintainer_email='kurjam18@htl-kaindorf.at',
    description='RoboCup2023',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'serial  = robocup.ros2_serial_mazebot:main', 
            'remote = robocup.remotecontroll_mazebot:main', 
        ],
    },
)
