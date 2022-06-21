# Autonomous-Mobile-Robot

This is the Arduino code for the robot, you need to simply dump the code on to the arduino board and run the following commands:

roscore

open a new terminal and type:

rosrun rosserial_python serial_node.py <port name>
  
open a new terminal and type:
  
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
  
To view the /cmd_vel, open a new terminal and type:
  
rostopic echo /cmd_vel
  
