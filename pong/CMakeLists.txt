cmake_minimum_required(VERSION 3.10)
project(pong VERSION 1.0)

# 1. Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Add GLFW (It has its own CMakeLists.txt)
# We disable GLFW documentation and tests to speed up our build
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)

# Add the GLM directory
add_subdirectory(external/glm)

# 3. Handle GLAD
# Assuming you put glad.c in external/glad/src and headers in external/glad/include
add_library(GLAD external/glad/src/glad.c)
target_include_directories(GLAD PUBLIC external/glad/include)

# 4. Create your executable
add_executable(${PROJECT_NAME} src/main.cpp src/window.cpp src/event.cpp src/eventHandler.cpp src/log.cpp src/utils.cpp src/engine.cpp)

# 5. Link everything
# GLFW creates a target named 'glfw'
# TODO: LEARN: WARNING: I dont know why i had to do glm::glm.
target_link_libraries(${PROJECT_NAME} PRIVATE glfw GLAD glm::glm ${CMAKE_DL_LIBS})

# Ensure headers can be found
target_include_directories(${PROJECT_NAME} PRIVATE external/glfw/include external/glad/include glm)