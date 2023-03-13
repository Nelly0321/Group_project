find_package(gtest REQUIRED)

add_executable(group_project_test main.cpp)

target_link_libraries(group_project_test PRIVATE
 GTest::GTest
 # Group_project library
)

add_test(gtest group_project_test)