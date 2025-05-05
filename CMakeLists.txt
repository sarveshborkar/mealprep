cmake_minimum_required(VERSION 3.10)

# Project name
project(MealPrep)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files (adjust path if needed)
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(MealPrep ${SOURCES})

# Include headers
include_directories(src)
