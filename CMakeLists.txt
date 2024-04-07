cmake_minimum_required(VERSION 3.12)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

# Set the build directory
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Add executable
add_executable(calculator main.cpp calculator.cpp infix_postfix.cpp)

# Include directories
target_include_directories(calculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# You might need to link additional libraries if needed
# target_link_libraries(calculator <library_name>)
