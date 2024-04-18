cmake_minimum_required(VERSION 3.10)

project(PatternHandler)

# Specify the C++ standard
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_STANDARD 17)

# Google Test setup
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Include the Google Test libraries
#include_directories(${googletest_SOURCE_DIR}/include ${googletest_SOURCE_DIR})

set(PATTERNHANDLER_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)
set(PATTERNHANDLER_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

include_directories(${PATTERNHANDLER_INCLUDE_DIR})

add_executable(PatternHandler main.cpp ${PATTERNHANDLER_SOURCE_DIR}/fileHandler.cpp ${PATTERNHANDLER_SOURCE_DIR}/patternHandler.cpp ${PATTERNHANDLER_SOURCE_DIR}/patternMapper.cpp ${PATTERNHANDLER_SOURCE_DIR}/Utils.cpp)

# Define the test executable
add_executable(
	pattern_test 
	${PATTERNHANDLER_SOURCE_DIR}/tst/test_main.cpp
	${PATTERNHANDLER_SOURCE_DIR}/tst/Utils_test.cpp
	${PATTERNHANDLER_SOURCE_DIR}/tst/fileHandler_test.cpp
	${PATTERNHANDLER_SOURCE_DIR}/Utils.cpp
	${PATTERNHANDLER_SOURCE_DIR}/fileHandler.cpp
)

# Link Google Test to the test executable
target_link_libraries(pattern_test gtest gtest_main)

# Include Google Test in the testing
include(GoogleTest)
gtest_discover_tests(pattern_test)

