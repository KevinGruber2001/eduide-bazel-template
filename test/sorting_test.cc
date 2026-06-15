#include "sorting.h"

#include <cstddef>

#include "gtest/gtest.h"

namespace {

TEST(SortingTest, BubbleSortAscending) {
    int a[] = {5, 3, 8, 1, 9, 2};
    bubble_sort(a, 6);
    int expected[] = {1, 2, 3, 5, 8, 9};
    for (std::size_t i = 0; i < 6; i++) {
        EXPECT_EQ(a[i], expected[i]);
    }
}

TEST(SortingTest, MergeSortAscending) {
    int a[] = {5, 3, 8, 1, 9, 2};
    merge_sort(a, 6);
    int expected[] = {1, 2, 3, 5, 8, 9};
    for (std::size_t i = 0; i < 6; i++) {
        EXPECT_EQ(a[i], expected[i]);
    }
}

TEST(SortingTest, HandlesSmallInputs) {
    int empty[] = {0};
    merge_sort(empty, 0);  // no-op, must not crash
    int single[] = {42};
    bubble_sort(single, 1);
    EXPECT_EQ(single[0], 42);
}

}  // namespace
