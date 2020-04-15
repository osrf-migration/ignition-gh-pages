cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
# Find the Ignition_Transport library
find_package(ignition-transport3 QUIET REQUIRED)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${IGNITION-TRANSPORT_CXX_FLAGS} ")
include_directories(${IGNITION-TRANSPORT_INCLUDE_DIRS})
link_directories(${IGNITION-TRANSPORT_LIBRARY_DIRS})

# Generate examples
if (EXISTS "${CMAKE_SOURCE_DIR}/publisher.cc")
  add_executable(publisher publisher.cc)
  target_link_libraries(publisher ${IGNITION-TRANSPORT_LIBRARIES})
endif()

if (EXISTS "${CMAKE_SOURCE_DIR}/subscriber.cc")
  add_executable(subscriber subscriber.cc)
  target_link_libraries(subscriber ${IGNITION-TRANSPORT_LIBRARIES})
endif()

add_library(drive_msg drive_mode.pb.cc) 
target_link_libraries(publisher drive_msg)

target_link_libraries(subscriber drive_msg)
