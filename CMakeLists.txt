cmake_minimum_required(VERSION 2.6)

# Configurable.

if (NOT DEFINED PROJECT_NAME)
	set(PROJECT_NAME "skeleton")
endif(NOT DEFINED PROJECT_NAME)

option(SKELETON_ENABLE_TESTS "Enables or disables tests. Disabled by default."
	OFF)


project(${PROJECT_NAME} CXX)
set(PROJECT_EXEC "${PROJECT_NAME}")
set(PROJECT_LIB "lib${PROJECT_NAME}")


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fstack-protector -s")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Werror -pedantic")

set(LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")


set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")
set(MAIN_SRC "${SRC_DIR}/main.cpp")
list(REMOVE_ITEM SRC_FILES "${MAIN_SRC}")

add_library("${PROJECT_LIB}" STATIC ${SRC_FILES})
set_target_properties(${PROJECT_LIB} PROPERTIES
	OUTPUT_NAME ${PROJECT_NAME})

add_executable("${PROJECT_EXEC}" "${MAIN_SRC}")
target_link_libraries("${PROJECT_EXEC}" "${PROJECT_LIB}")


#
# Testing rules.
#

if (SKELETON_ENABLE_TESTS)

	set(TEST_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test")
	file(GLOB_RECURSE TEST_SRC_FILES "${TEST_SRC_DIR}/*.cpp")

	set(GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/gtest")
	add_subdirectory(${GTEST_DIR})
	include_directories("${GTEST_DIR}/include")


	add_custom_target(run-tests COMMAND "")
	add_custom_target(run-memleak-tests COMMAND "")

	find_program(VALGRIND "valgrind")

	foreach(TEST_SRC ${TEST_SRC_FILES})
		get_filename_component(TEST_NAME "${TEST_SRC}" NAME_WE)

		add_executable("${TEST_NAME}" ${TEST_SRC})
		add_dependencies("${TEST_NAME}" "${PROJECT_LIB}")
		target_link_libraries(${TEST_NAME} "gtest" "gtest_main"
			${ALL_LIBS})

		set(TEST_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/Testing/bin")
		set_target_properties("${TEST_NAME}" PROPERTIES
			RUNTIME_OUTPUT_DIRECTORY "${TEST_OUTPUT_DIR}")

		add_custom_command(TARGET run-tests
			COMMAND "${TEST_OUTPUT_DIR}/${TEST_NAME}")

		add_custom_command(TARGET run-memleak-tests
			COMMAND "${VALGRIND}"
			ARGS "--leak-check=full"
				"${TEST_OUTPUT_DIR}/${TEST_NAME}"
		)
	endforeach()
endif()
