cmake_minimum_required(VERSION 3.14)
project(quickfixc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

find_library(QuickFIX_LIBRARIES QuickFIX REQUIRED)
find_path(QuickFIX_INCLUDE_DIRS QuickFIX REQUIRED)

message(STATUS "Found QuickFIX library: ${QuickFIX_LIBRARIES}")
message(STATUS "Found QuickFIX include dir: ${QuickFIX_INCLUDE_DIRS}")

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${QuickFIX_INCLUDE_DIRS})

add_library(quickfixc SHARED ${SOURCES})

file(GLOB_RECURSE SOURCES src/*.cpp)

target_sources(quickfixc PRIVATE ${SOURCES})

target_link_libraries(quickfixc PRIVATE ${QuickFIX_LIBRARIES})

install(TARGETS quickfixc LIBRARY DESTINATION lib)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include/quickfixc)