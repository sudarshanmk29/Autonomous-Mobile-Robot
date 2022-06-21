**HOW TO USE THIS REPOSITORY**

Create a ros workspace. The detailed instructions to create a ros workspace is given in the official ros docunmentation.
http://wiki.ros.org/catkin/Tutorials/create_a_workspace

In the Workspace, move to the src folder and type the below command and press enter:

            git clone https://github.com/sudarshanmk29/Autonomous-Mobile-Robot.git
            cd ..
            catkin_make

With the above command, the repository files will be loaded on to the workspace.

**Note: To ensure all the necessary packages are installed, type the below command outside the src folder inside the ROS Workspace:**

      source devel/setup.bash
      rosdep install --from-paths src --ignore-src -r -y

**1) TO LAUNCH THE SIMULATION**

Open a new terminal, navigate to your workspace and type the following commands:

      source devel/setup.bash
      roslaunch wmr_description gazebo.launch

*The above command will launch the robot in an empty world*

*To Launch the robot in a custom world type the following command:*

      roslaunch wmr_description gazebo.launch spawn_world:=true

**2) TO LAUNCH RVIZ**

Open a new terminal and type:

      rosrun rviz rviz

*File -> Open Config -> wmr_description -> rviz ->urdf.rviz*

**Note: Keep the Gazebo Simulator runnning to launch rviz. Please don't cancel the commands running on the simulation terminal**

**3) To Autonomously Run the Robot**

In the rviz, Select the 2D Nav Goal and give a goal point.

That's it the robot starts moving to the goal location autonomously. The Video below is a demo of the Simulation


https://user-images.githubusercontent.com/54470983/174720114-0f76b046-5397-4275-b320-af5599d0be5b.mp4
