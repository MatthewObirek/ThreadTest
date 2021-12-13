cmake_minimum_required (VERSION 3.21.1)

project(ThreadTest)
# Add source to this project's executable.
set (CMAKE_CXX_STANDARD 11)

add_subdirectory (Game-Libs)

add_executable (Main "Main.cpp" )

target_link_libraries( Main 
                        Object
                        Debug)
