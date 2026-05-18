cmake_minimum_required(VERSION 3.10)  
project(launcher)


find_package(PkgConfig REQUIRED)


# Add executable
add_executable(launcher src/main.c )

# Link libraries
target_link_libraries(launcher)
