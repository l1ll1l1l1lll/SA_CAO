from setuptools import setup

package_name = 'pure_pursuit'

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
    maintainer='y',
    maintainer_email='yuhao_cao@outlook.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'marker_relay_node = pure_pursuit.marker_relay_node:main',
        'get_pose = pure_pursuit.get_pose:main',
        'pure_pursuit_node = pure_pursuit.pure_pursuit_node:main',
        ],
    },
)
