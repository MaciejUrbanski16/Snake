# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# There are source files with tests:
add_executable(Google_Tests_run SegmentFoodTests.cpp ../Segment.cpp ../Segment.h SnakeTests.cpp ../Snake.h ../Snake.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)