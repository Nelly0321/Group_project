find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(group_project_test main.cpp)

target_link_libraries(group_project_test PRIVATE
 GTest::GTest
 # Group_project library
)

gtest_discover_tests(group_project_test)