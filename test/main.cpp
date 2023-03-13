#include <gtest/gtest.h>

// supress gtest warnings https://github.com/google/googletest/issues/2442
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
TEST(GroupProject, DummyTest)
{
    auto dummyVal1 = 0;
    auto dummyVal2 = 0;
    EXPECT_EQ(dummyVal1, dummyVal2);
}


// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}