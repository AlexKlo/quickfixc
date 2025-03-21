cmake_minimum_required(VERSION 3.14)
project(quickfixc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

find_library(QuickFIX_LIBRARIES QuickFIX REQUIRED)
find_path(QuickFIX_INCLUDE_DIRS QuickFIX REQUIRED)

message(STATUS "Found QuickFIX library: ${QuickFIX_LIBRARIES}")
message(STATUS "Found QuickFIX include dir: ${QuickFIX_INCLUDE_DIRS}")

find_package(OpenSSL REQUIRED)

if(OPENSSL_FOUND)
    message(STATUS "Found OpenSSL: ${OPENSSL_LIBRARIES}")
    message(STATUS "OpenSSL Include Dir: ${OPENSSL_INCLUDE_DIR}")
else()
    message(FATAL_ERROR "OpenSSL not found")
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${QuickFIX_INCLUDE_DIRS})
include_directories(${OPENSSL_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(quickfixc SHARED ${SOURCES})

target_sources(quickfixc PRIVATE ${SOURCES})

target_link_libraries(quickfixc PRIVATE ${QuickFIX_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS quickfixc LIBRARY DESTINATION lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include/quickfixc)