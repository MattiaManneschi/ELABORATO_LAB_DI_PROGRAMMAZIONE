cmake_minimum_required(3.20)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp Test1.cpp Test2.cpp)
add_executable(runListTests ${TEST_SOURCE_FILES})
target_link_libraries(runListTests gtest gtest_main core)