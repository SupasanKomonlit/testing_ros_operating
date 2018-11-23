cmake_minimum_required(VERSION 2.8.3)
project(tutorial_publish)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tutorial_msgs
)

catkin_package(
#	INCLUDE_DIRS include
	LIBRARIES tutorial_publish
	CATKIN_DEPENDS roscpp  
	DEPENDS 
)

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

add_executable( example_publish src/example_publish.cpp)

add_dependencies( example_publish ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries( example_publish ${catkin_LIBRARIES} )
