cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(example_project LANGUAGES C CXX VERSION 3.0.0)

find_package(ignition-common3 REQUIRED COMPONENTS graphics)
find_package(ignition-math6 REQUIRED)
find_package(ignition-msgs2 REQUIRED)
find_package(ignition-transport5 REQUIRED COMPONENTS log)

add_library(example
  example.cc
)

target_link_libraries(
  example
    ignition-transport5::core
    ignition-transport5::log
)

install(TARGETS example
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
