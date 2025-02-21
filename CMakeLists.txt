cmake_minimum_required(VERSION 3.10)
project(shell C)

# C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# comp flags
add_compile_options(-Wall -Wextra)

# output dirs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add include dirs
include_directories(${PROJECT_SOURCE_DIR}/include)

# collect src files
file(GLOB_RECURSE SOURCES
  "src/*.c"
  "src/builtins/*.c"
)
list(REMOVE_ITEM SHELL_SOURCES "${PROJECT_SOURCE_DIR}/src/main.c")

# create lib
add_library(shell_lib STATIC ${SOURCES})

# make exec
add_executable(shell src/main.c)
target_link_libraries(shell PRIVATE shell_lib)

# unit testing
enable_testing()
add_subdirectory(tests)

# rules
# install(TARGETS ${PROJECT_NAME}
#   RUNTIME DESTINATION bin
# )
