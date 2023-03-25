from setuptools import setup

package_name = 'publisher'

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
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'openMV = publisher.openmv_cam_pub.py:main',
            'rc_sensor = publisher.rc_sensor_pub.py:main',

        ],
    },
)
