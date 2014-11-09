cmake_minimum_required(VERSION 2.6)
project(gmock_sample CXX)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
set(PROJECT_EXEC "${PROJECT_NAME}")
set(PROJECT_LIB "lib${PROJECT_NAME}")

option(GMOCK_SAMPLE_ENABLE_TESTS "Enables or disables tests. Disabled by default."
	OFF)


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}.")


set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fstack-protector -s")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Werror -pedantic")


set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")
set(MAIN_SRC "${SRC_DIR}/main.cpp")
list(REMOVE_ITEM SRC_FILES "${MAIN_SRC}")

add_library("${PROJECT_LIB}" STATIC ${SRC_FILES})
set_target_properties(${PROJECT_LIB} PROPERTIES
	OUTPUT_NAME ${PROJECT_NAME})

add_executable("${PROJECT_EXEC}" "${MAIN_SRC}")
target_link_libraries("${PROJECT_EXEC}" "${PROJECT_LIB}")


# Compile tests.
if (GMOCK_SAMPLE_ENABLE_TESTS)
	set(TESTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")
	add_subdirectory(${TESTS_DIR})
endif()
