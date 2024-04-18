#include <gtest/gtest.h>
#include "Utils.hpp"

using namespace Utils;
TEST(UtilsTest, IsCalledToString) {
    EXPECT_EQ(isCalledToString(true), "true");
    EXPECT_EQ(isCalledToString(false), "false");
}

// Test for converting string to boolean
TEST(UtilsTest, IsCalledToBool) {
    EXPECT_TRUE(Utils::isCalledToBool("true"));
    EXPECT_TRUE(Utils::isCalledToBool("True"));
    EXPECT_FALSE(Utils::isCalledToBool("false"));
    EXPECT_FALSE(Utils::isCalledToBool("anyOtherValue"));
}

// Test for printing patterns (mocking std::cout)
TEST(UtilsTest, PrintPatterns) {
    std::vector<PatternCall> patterns = {
        {1, "Pattern1", "file1.pat", true},
        {2, "Pattern2", "file2.pat", false}
    };

    testing::internal::CaptureStdout();  // Start capturing stdout
    Utils::printPatterns(patterns);
    std::string output = testing::internal::GetCapturedStdout();  // Stop capturing stdout

    std::string expectedOutput =
        "1,Pattern1,file1.pat,1\n"
        "2,Pattern2,file2.pat,0\n";
    EXPECT_EQ(output, expectedOutput);
}

