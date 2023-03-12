find_package(gtest REQUIRED)

add_executable(test main.cpp)

target_link_libraries(test PRIVATE
 GTest::GTest
 # Group_project library
)