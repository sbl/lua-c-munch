project(munchhausen)
cmake_minimum_required(VERSION 3.17)

add_executable(munch munch.c)

add_executable(munchcpp munch.cpp)
target_include_directories(munchcpp PRIVATE /usr/local/include)
set_target_properties(munchcpp PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
)
