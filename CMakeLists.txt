cmake_minimum_required(VERSION 3.16)
project(MySFMLGame)

# Use C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# SFML include direcctories
include_directories("C:/msys64/ucrt64/include")

# Collect all source files automatically
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Specify the output executable
add_executable(main ${SOURCES})

# Link SFML3 libraries
target_link_libraries(main PRIVATE sfml-window sfml-system sfml-graphics)

# Set output directory for compiled files
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output")
