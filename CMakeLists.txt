cmake_minimum_required(VERSION 3.10)  
project(launcher)

# Add executable
add_executable(launcher src/main.c )

# Link libraries
target_link_libraries(launcher)
