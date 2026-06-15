#include "stats.h"

#include "gtest/gtest.h"

namespace {

constexpr int kData[] = {5, 3, 8, 1, 9, 2};

TEST(StatsTest, Mean) {
    EXPECT_DOUBLE_EQ(stat_mean(kData, 6), 28.0 / 6.0);
}

TEST(StatsTest, MedianEvenLength) {
    EXPECT_DOUBLE_EQ(stat_median(kData, 6), 4.0);
}

TEST(StatsTest, Max) {
    EXPECT_EQ(stat_max(kData, 6), 9);
}

}  // namespace
