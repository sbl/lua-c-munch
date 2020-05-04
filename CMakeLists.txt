project(munchhausen)
cmake_minimum_required(VERSION 3.17)

add_executable(munch munch.c)
target_include_directories(munch PRIVATE
  /usr/local/include
)
