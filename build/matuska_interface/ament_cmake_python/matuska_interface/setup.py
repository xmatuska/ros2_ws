from setuptools import find_packages
from setuptools import setup

setup(
    name='matuska_interface',
    version='0.0.0',
    packages=find_packages(
        include=('matuska_interface', 'matuska_interface.*')),
)
