cmake_minimum_required(VERSION 3.10)  
project(launcher)

# Find the curl library
find_package(CURL REQUIRED)


# Find the jansson library
#find_package(Jansson REQUIRED)
find_package(PkgConfig REQUIRED)


# Add executable
add_executable(launcher src/main.c )

# Link libraries
target_link_libraries(launcher)
