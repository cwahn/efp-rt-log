cmake_minimum_required(VERSION 3.5.0)
project(efp_logger VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include("cmake/CPM.cmake")

CPMAddPackage(
    NAME efp
    URL "https://github.com/cwahn/efp/archive/refs/tags/v0.1.1-beta.tar.gz"
)

# Neccessary for ESP32 support
set(FMT_INSTALL OFF CACHE BOOL "Disable fmt install/export")
set(FMT_EXPORT OFF CACHE BOOL "Disable fmt export targets")
CPMAddPackage(
    NAME fmt
    URL "https://github.com/fmtlib/fmt/archive/refs/tags/10.2.1.tar.gz"
)

add_library(efp_logger INTERFACE)
target_include_directories(efp_logger INTERFACE include)
target_link_libraries(efp_logger INTERFACE efp fmt::fmt)

# Only if the project is the top-most project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    enable_testing()

    add_subdirectory(example)
endif()