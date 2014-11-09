cmake_minimum_required(VERSION 2.6)

set(TEST_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
file(GLOB_RECURSE TEST_SRC_FILES "${TEST_SRC_DIR}/*.cpp")

set(GMock_ROOT "${LIBS_DIR}/gmock")
find_package(GMock REQUIRED)

set(GMOCK_DIR "${LIBS_DIR}/gmock")
set(GTEST_DIR "${GMOCK_DIR}/gtest")
include_directories("${GMOCK_DIR}/include" "${GTEST_DIR}/include"
	${SRC_DIR})


add_custom_target(run-tests COMMAND "")
add_custom_target(run-memleak-tests COMMAND "")

find_program(VALGRIND "valgrind")

foreach(TEST_SRC ${TEST_SRC_FILES})
	get_filename_component(TEST_NAME "${TEST_SRC}" NAME_WE)

	add_executable("${TEST_NAME}" ${TEST_SRC})
	add_dependencies("${TEST_NAME}" "${PROJECT_LIB}")
	target_link_libraries(${TEST_NAME} gmock gtest gmock_main
		${PROJECT_LIB})

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
