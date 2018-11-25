cmake_minimum_required(VERSION 2.8.3)
project(tutorial_boost)

find_package(catkin REQUIRED roscpp)

find_package(Boost REQUIRED COMPONENTS )

catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES tutorial_boost
  CATKIN_DEPENDS roscpp
  DEPENDS Boost
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
 ${Boost_INCLUDE_DIRS}
)

add_executable( matrix_boost src/matrix_boost.cpp
)

target_link_libraries( matrix_boost ${catkin_LIBRARIES} ${Boost_LIBRARIES})
