from setuptools import find_packages
from setuptools import setup

setup(
    name='mazebot_msgs',
    version='1.0.0',
    packages=find_packages(
        include=('mazebot_msgs', 'mazebot_msgs.*')),
)
