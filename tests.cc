#include <gtest/gtest.h>
#include "code.h"

class EffectiveModernCPPTests : public ::testing::Test {};

// actually from https://ds9a.nl/articles/posts/cpp-2/
TEST_F(EffectiveModernCPPTests, test_async_factorial) {
    EXPECT_DOUBLE_EQ(1.216451008878336e+17, main_factorial(19, 12));
}
