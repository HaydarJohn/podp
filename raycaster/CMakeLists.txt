cmake_minimum_required(VERSION 3.10)
project(RaycasterGame)

# 1. Force FreeGLUT to build for macOS Cocoa instead of X11
if(APPLE)
    set(FREEGLUT_COCOA ON CACHE BOOL "" FORCE)
    set(FREEGLUT_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
    set(FREEGLUT_BUILD_STATIC_LIBS OFF CACHE BOOL "" FORCE)
endif()

# 2. Add the submodule
add_subdirectory(freeglut)

# 3. Setup your project
set(CMAKE_CXX_STANDARD 17)
find_package(OpenGL REQUIRED)

# 4. Define the executable
add_executable(RaycasterGame raycaster.cpp)

# 5. Link libraries
# We link to 'freeglut' (the submodule target) and system OpenGL
target_link_libraries(RaycasterGame PRIVATE freeglut OpenGL::GL OpenGL::GLU)

# 6. Final macOS-specific framework link
if(APPLE)
    target_link_libraries(RaycasterGame PRIVATE "-framework Cocoa -framework IOKit -framework CoreVideo")
endif()