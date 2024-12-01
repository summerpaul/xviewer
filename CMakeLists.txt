cmake_minimum_required(VERSION 3.10.0)
project(xviewer VERSION 1.0.0 LANGUAGES CXX)

IF (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_EXAMPLE "Build example" ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output/bin)

if(WIN32)
    set(VCPKG_ROOT "D:/vcpkg" CACHE PATH "Path to vcpkg root directory")
    set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "vcpkg target triplet")
    set(VCPKG_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-windows/include)
    set(VCPKG_LIB_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-windows/lib)
elseif(APPLE)
    set(VCPKG_ROOT "~/vcpkg" CACHE PATH "Path to vcpkg root directory")
    set(VCPKG_TARGET_TRIPLET "arm64-osx" CACHE STRING "vcpkg target triplet")
    set(VCPKG_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/arm64-osx/include)
    set(VCPKG_LIB_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/arm64-osx/lib)
elseif(UNIX)
    set(VCPKG_ROOT "~/vcpkg" CACHE PATH "Path to vcpkg root directory")
    set(VCPKG_TARGET_TRIPLET "x64-linux" CACHE STRING "vcpkg target triplet")
    set(VCPKG_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-linux/include)
    set(VCPKG_LIB_DIRS ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-linux/lib)
endif()

include(${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)
include_directories(${VCPKG_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/resources/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)
add_subdirectory(source)

file(COPY resources/font/msyh.ttf DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/output/resources/font/msyh.ttf)
file(COPY resources/icon/fa-solid-900.ttf DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/output/resources/icon/fa-solid-900.ttf)

if(BUILD_EXAMPLE)
    add_subdirectory(example)
endif()


