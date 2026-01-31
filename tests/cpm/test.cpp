#include <constest.hpp>
#include <gtest/gtest.h>

TEST(SimpleTest, BasicAssertion)
{

    EXPECT_EQ(1 + 1, 2);
}

TEST(SimpleTest, ConstestedAssertion)
{
    constexpr int value = 42;
    CONSTEXPR_SECTION("Test constexpr section")
    {
        CONSTEXPR_EXPECT_EQ(value, 42);
    };
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
