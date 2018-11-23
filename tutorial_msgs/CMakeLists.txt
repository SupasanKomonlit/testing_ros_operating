cmake_minimum_required(VERSION 2.8.3)
project(tutorial_msgs)

find_package(catkin REQUIRED std_msgs message_generation)

add_message_files(
   FILES
   SingleNumber.msg
)

generate_messages(
   DEPENDENCIES
   std_msgs
 )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES 
#  CATKIN_DEPENDS 
#  DEPENDS system_lib
)

include_directories(
# include
# ${catkin_INCLUDE_DIRS}
)
