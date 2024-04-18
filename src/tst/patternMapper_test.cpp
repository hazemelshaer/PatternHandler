#include <gtest/gtest.h>
#include "patternMapper.hpp"

class PatternMapperTest : public ::testing::Test {
protected:
    PatternMapper mapper;

    void SetUp() override {
        // Add some patterns to the mapper for testing
        mapper.addToPatterns(PatternCall{1, "PatternOne", "/path/one", true});
        mapper.addToPatterns(PatternCall{2, "PatternTwo", "/path/two", false});
        mapper.addToPatterns(PatternCall{3, "PatternOne", "/path/three", true});
    }
};

// Test for getting pattern by ID
TEST_F(PatternMapperTest, GetByID) {
    auto pattern = mapper.getByID(1);
    EXPECT_EQ(1, pattern.id);
    EXPECT_EQ("PatternOne", pattern.name);
    EXPECT_TRUE(pattern.flag);

    // Test for an ID that does not exist
    auto nonExistent = mapper.getByID(99);
    EXPECT_EQ(0, nonExistent.id); // Assuming returned PatternCall has id 0 if not found
}

// Test for getting patterns by name
TEST_F(PatternMapperTest, GetByName) {
    auto patterns = mapper.getByName("PatternOne");
    ASSERT_EQ(2, patterns.size());
    EXPECT_EQ(1, patterns[0].id);
    EXPECT_EQ(3, patterns[1].id);

    // Test for a name that does not exist
    auto emptyResult = mapper.getByName("NoName");
    EXPECT_TRUE(emptyResult.empty());
}

// Test for getting patterns by file path
TEST_F(PatternMapperTest, GetByPath) {
    auto patterns = mapper.getByPath("/path/one");
    ASSERT_EQ(1, patterns.size());
    EXPECT_EQ("PatternOne", patterns[0].name);

    // Test for a path that does not exist
    auto emptyPathResult = mapper.getByPath("/no/path");
    EXPECT_TRUE(emptyPathResult.empty());
}

// Test for getting patterns by flag
TEST_F(PatternMapperTest, GetByFlag) {
    auto truePatterns = mapper.getByFlag(true);
    ASSERT_EQ(2, truePatterns.size()); // Check for patterns with true flag

    auto falsePatterns = mapper.getByFlag(false);
    ASSERT_EQ(1, falsePatterns.size()); // Check for patterns with false flag
}

// Test for adding to patterns
TEST_F(PatternMapperTest, AddToPatterns) {
    PatternCall newPattern = {4, "PatternNew", "/path/new", false};
    mapper.addToPatterns(newPattern);
    auto patterns = mapper.getPatterns();
    EXPECT_EQ(4, patterns.size());
    EXPECT_EQ(4, patterns.back().id);
}

// Test for getting all patterns
TEST_F(PatternMapperTest, GetPatterns) {
    auto patterns = mapper.getPatterns();
    ASSERT_EQ(3, patterns.size()); // Initially three patterns were added
}
