cmake_minimum_required (VERSION 3.10.2)

project (ADS)
# Set the output folder where your program will be created
include_directories(${PROJECT_SOURCE_DIR})
add_executable(app Main.cpp src/Trie.cpp)  # be sure there's exactly one main() function in the source files