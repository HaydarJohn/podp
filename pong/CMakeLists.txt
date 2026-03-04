cmake_minimum_required(VERSION 3.10)
project(pong VERSION 1.0)

# 1. Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)

# 2. Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# 3. Generate embedded shaders in Release mode
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    # If shaders.h doesn't exist, generate it
    if(NOT EXISTS ${CMAKE_SOURCE_DIR}/external/shaders/shaders.h)
        message(STATUS "shaders.h not found, generating from source files...")
        
        # Create external/shaders directory
        file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/external/shaders)
        
        # Read shader files
        file(READ ${CMAKE_SOURCE_DIR}/src/test.vert VERT_SHADER_CONTENT)
        file(READ ${CMAKE_SOURCE_DIR}/src/test.frag FRAG_SHADER_CONTENT)
        
        # Escape backslashes for C string
        string(REPLACE "\\" "\\\\" VERT_SHADER_CONTENT "${VERT_SHADER_CONTENT}")
        string(REPLACE "\\" "\\\\" FRAG_SHADER_CONTENT "${FRAG_SHADER_CONTENT}")
        
        # Generate header file
        file(WRITE ${CMAKE_SOURCE_DIR}/external/shaders/shaders.h 
"// Auto-generated - do not edit manually
#ifndef SHADERS_H
#define SHADERS_H

const char* VERT_SHADER = R\"(
${VERT_SHADER_CONTENT}
)\";

const char* FRAG_SHADER = R\"(
${FRAG_SHADER_CONTENT}
)\";

#endif
")
    endif()
    
    message(STATUS "Release build: Embedding shaders into binary")
    
    # This define tells the code to use embedded shaders
    add_compile_definitions(PONGPONG_EMBED_SHADERS)
endif()

# 4. Add GLFW (It has its own CMakeLists.txt)
set(GLFW_BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)

# Add SoLoud
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(SOLOUD_STATIC ON CACHE BOOL "" FORCE)
set(SOLOUD_BACKEND_COREAUDIO ON CACHE BOOL "" FORCE)
set(SOLOUD_BACKEND_NULL OFF CACHE BOOL "" FORCE)
set(SOLOUD_BACKEND_SDL2 OFF CACHE BOOL "" FORCE)
add_subdirectory(external/soloud/contrib)

# Add the GLM directory
add_subdirectory(external/glm)

# 5. Handle GLAD
add_library(GLAD external/glad/src/glad.c)
target_include_directories(GLAD PUBLIC external/glad/include)

# 6. Create your executable
add_executable(${PROJECT_NAME} src/main.cpp src/utils.cpp src/paddle.cpp src/ball.cpp)

# 7. Link everything
target_link_libraries(${PROJECT_NAME} PRIVATE glfw GLAD glm::glm ${CMAKE_DL_LIBS} soloud)

# Ensure headers can be found
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/external/glfw/include 
    ${CMAKE_SOURCE_DIR}/external/glad/include 
    ${CMAKE_SOURCE_DIR}/external/glm
    ${CMAKE_SOURCE_DIR}/external/shaders
    ${CMAKE_SOURCE_DIR}/external/soloud/include
)
