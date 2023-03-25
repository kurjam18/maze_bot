from setuptools import setup

package_name = 'mazebot_v1'

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
    description='Mazebot Diplomarbeit',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'master = mazebot_v1.mazebot_master.py:main',
                'motor_controller = mazebot_v1.motor_controller.py:main' 
        ],
    },
)
