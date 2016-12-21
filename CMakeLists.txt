cmake_minimum_required(VERSION 3.6)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release) [Release chosen by default]" FORCE)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Building for release...")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building for debug...")
else()
    message(FATAL_ERROR "Build type \"${CMAKE_BUILD_TYPE}\" not recognized!")
endif()

# Uncomment to use static libraries
# set(STATIC_LIBS 1)

# Set architecture to build for (32 or 64 bit - x86 | x64)
set(COMPILE_ARCH "x86")

# Set executable (binary) name
set(EXECUTABLE_NAME The_world)

# This sets the Project name
project(The_world)

# List of source files
set(SOURCE_FILES
        src/main.cpp
        src/Systems/WindowController.cpp
        src/Systems/WindowController.hpp
        src/Patterns/ObserverPattern.cpp
        src/Patterns/ObserverPattern.hpp
        src/Base/Event.cpp
        src/Base/Event.hpp
        src/Base/Entity.cpp
        src/Base/Entity.hpp
        src/Base/Types.hpp
        src/Base/System.cpp
        src/Base/System.hpp
        src/Base/Logger.cpp
        src/Base/Logger.cpp
        src/Base/Logger.hpp
        src/Systems/GraphicsSystem.cpp
        src/Systems/GraphicsSystem.hpp
        src/Systems/ResourceSystem.cpp
        src/Systems/ResourceSystem.hpp)

# Set C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Set Add source files of executable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Modules" ${CMAKE_MODULE_PATH})

# Static or shared libs
if(STATIC_LIBS)
    message(STATUS "Compiling static...\n")
else()
    message(STATUS "Compiling shared...\n")
endif()

# Load OpenGL
find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
    message(STATUS "OPENGL_INCLUDE_DIR:")
    message(STATUS "${OPENGL_INCLUDE_DIR}\n")
    target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
    message(STATUS "OPENGL_LIBRARIES:")
    message(STATUS "${OPENGL_LIBRARIES}\n")
endif()

# Load SFML
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    message(STATUS "SFML_INCLUDE_DIR:")
    message(STATUS "${SFML_INCLUDE_DIR}\n")
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
    message(STATUS "SFML_LIBRARIES:")
    message(STATUS "${SFML_LIBRARIES}\n")
endif()

# Load Glew
set(GLEW_LOCATION "${CMAKE_SOURCE_DIR}/libs/glew-cmake")
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIR})
    message(STATUS "GLEW_INCLUDE_DIR:")
    message(STATUS "${GLEW_INCLUDE_DIR}\n")
    target_link_libraries(${EXECUTABLE_NAME} ${GLEW_LIBRARIES})
    message(STATUS "GLEW_LIBRARIES:")
    message(STATUS "${GLEW_LIBRARIES}\n")
endif()