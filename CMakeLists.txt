project(munchhausen)
cmake_minimum_required(VERSION 3.17)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# ------------------------------------------------------

add_library(mu SHARED mu.c)
target_include_directories(mu PRIVATE
  /usr/local/include
  )
target_link_directories(mu PRIVATE /usr/local/lib)
target_link_libraries(mu lua)
target_compile_options(mu
  PRIVATE -Wall -Wextra -pedantic -Werror
)

set_target_properties(mu PROPERTIES
  POSITION_INDEPENDENT_CODE ON
  SUFFIX .so
  )


# ------------------------------------------------------

add_executable(munch munch.c)
target_compile_options(munch
  PRIVATE -Wall -Wextra -pedantic -Werror
  )

target_include_directories(munch PRIVATE
  /usr/local/include
  )
