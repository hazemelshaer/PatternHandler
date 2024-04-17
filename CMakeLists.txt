cmake_minimum_required(VERSION 3.10)

project(PatternHandler)
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_STANDARD 17)

set(PATTERNHANDLER_INCLUDE_DIR /Users/hazem/Xcode/PatternHandlerProject/inc)
set(PATTERNHANDLER_SOURCE_DIR /Users/hazem/Xcode/PatternHandlerProject/src)

include_directories(${PATTERNHANDLER_INCLUDE_DIR})
add_executable(PatternHandler main.cpp ${PATTERNHANDLER_SOURCE_DIR}/fileHandler.cpp ${PATTERNHANDLER_SOURCE_DIR}/patternHandler.cpp ${PATTERNHANDLER_SOURCE_DIR}/patternMapper.cpp ${PATTERNHANDLER_SOURCE_DIR}/Utils.cpp)
