#include <gtest/gtest.h>
#include "fileHandler.hpp"

class FileHandlerTest : public ::testing::Test {
protected:
    std::string testFileName;

    void SetUp() override {
        testFileName = "temp_test_file.txt"; // Temporary file for testing
    }

    void TearDown() override {
        remove(testFileName.c_str()); // Ensure cleanup of test file after each test
    }

    // Helper function to read the entire content of a file into a string
    std::string readFileContent(const std::string& filename) {
        std::ifstream file(filename);
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return content;
    }

    // Helper function to write content to a file
    void writeInitialContent(const std::string& filename, const std::string& content) {
        std::ofstream file(filename);
        file << content;
        file.close();
    }
};

// Test for writing to a file
TEST_F(FileHandlerTest, WriteToFile) {
    FileHandler handler;
    std::vector<PatternCall> patterns = {
        {1, "PatternOne", "/path/to/pattern1.pat", true},
        {2, "PatternTwo", "/path/to/pattern2.pat", false}
    };

    handler.writeToFile(testFileName, patterns);

    std::string expectedContent = 
        "1,PatternOne,/path/to/pattern1.pat,true\n"
        "2,PatternTwo,/path/to/pattern2.pat,false\n";

    std::string actualContent = readFileContent(testFileName);
    EXPECT_EQ(expectedContent, actualContent);
}

// Test for reading from a file
TEST_F(FileHandlerTest, ReadFromFile) {
    std::string content = 
        "1,PatternOne,/path/to/pattern1.pat,true\n"
        "2,PatternTwo,/path/to/pattern2.pat,false\n";
    writeInitialContent(testFileName, content);

    FileHandler handler;
    auto patterns = handler.readFromFile(testFileName);

    ASSERT_EQ(2, patterns.size());
    EXPECT_EQ(1, patterns[0].id);
    EXPECT_EQ("PatternOne", patterns[0].name);
    EXPECT_EQ("/path/to/pattern1.pat", patterns[0].patternFile);
    EXPECT_TRUE(patterns[0].flag);

    EXPECT_EQ(2, patterns[1].id);
    EXPECT_EQ("PatternTwo", patterns[1].name);
    EXPECT_EQ("/path/to/pattern2.pat", patterns[1].patternFile);
    EXPECT_FALSE(patterns[1].flag);
}
