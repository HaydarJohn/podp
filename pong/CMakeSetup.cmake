message(STATUS "Setting up build directories...")

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/build/debug)
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/build/release)

execute_process(
    COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR} -B ${CMAKE_SOURCE_DIR}/build/debug -DCMAKE_BUILD_TYPE=Debug
    RESULT_VARIABLE debug_result
)

if(debug_result)
    message(FATAL_ERROR "Debug configuration failed!")
endif()

execute_process(
    COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR} -B ${CMAKE_SOURCE_DIR}/build/release -DCMAKE_BUILD_TYPE=Release
    RESULT_VARIABLE release_result
)

if(release_result)
    message(FATAL_ERROR "Release configuration failed!")
endif()

message(STATUS "")
message(STATUS "========================================")
message(STATUS "Build directories created successfully!")
message(STATUS "========================================")
message(STATUS "")
message(STATUS "To build Debug:")
message(STATUS "  cd build/debug")
message(STATUS "  cmake --build .")
message(STATUS "")
message(STATUS "To build Release:")
message(STATUS "  cd build/release")
message(STATUS "  cmake --build . --config Release")
