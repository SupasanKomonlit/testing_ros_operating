cmake_minimum_required(VERSION 2.8.3)
project(tutorial_subscribe)

find_package(catkin REQUIRED tutorial_msgs roscpp)

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES tutorial_subscribe
  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_executable(example_subscribe src/example_subscribe.cpp)

add_dependencies(example_subscribe ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries( example_subscribe ${catkin_LIBRARIES} )
