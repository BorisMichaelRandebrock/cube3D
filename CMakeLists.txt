cmake_minimum_required(VERSION 3.10)
project(42Cube3d)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# Find GLFW
find_package(glfw3 3.3 REQUIRED CONFIG)
include_directories(${GLFW_INCLUDE_DIRS})

# Add other includes
include_directories(include)

# Add executable
add_executable(42Cube3d src/main.c)

# Link libraries
target_link_libraries(42Cube3d ${OPENGL_LIBRARIES} glfw)
