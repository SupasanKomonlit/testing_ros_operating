cmake_minimum_required(VERSION 2.8.3)
project(tutorial_msg)

find_package(catkin REQUIRED COMPONENTS
	std_msgs
	message_generation
)

add_message_files(
	FILES
	SingleNumber.msg
)

generate_messages( DEPENDENCIES std_msgs)

catkin_package(
#	INCLUDE_DIRS include
	LIBRARIES tutorial_msg
#	CATKIN_DEPENDS std_msgs
#	DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
