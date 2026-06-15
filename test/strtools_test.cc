#include "strtools.h"

#include <cstring>

#include "gtest/gtest.h"

namespace {

TEST(StrToolsTest, WordCount) {
    EXPECT_EQ(str_word_count("the quick brown fox"), 4);
    EXPECT_EQ(str_word_count("   spaced   out  "), 2);
    EXPECT_EQ(str_word_count(""), 0);
}

TEST(StrToolsTest, ReverseWords) {
    char out[64];
    size_t n = str_reverse_words("the quick brown fox", out, sizeof(out));
    EXPECT_NE(n, static_cast<size_t>(-1));
    EXPECT_STREQ(out, "fox brown quick the");
}

TEST(StrToolsTest, ReverseWordsTooSmall) {
    char out[4];
    EXPECT_EQ(str_reverse_words("the quick brown fox", out, sizeof(out)),
              static_cast<size_t>(-1));
}

}  // namespace
