#include "sorting.h"

#include "check.h"

int main(void) {
    int a[] = {5, 3, 8, 1, 9, 2};
    int expected[] = {1, 2, 3, 5, 8, 9};

    int b[6];
    for (int i = 0; i < 6; i++) {
        b[i] = a[i];
    }
    bubble_sort(b, 6);
    for (int i = 0; i < 6; i++) {
        CHECK_EQ_INT(b[i], expected[i]);
    }

    int m[6];
    for (int i = 0; i < 6; i++) {
        m[i] = a[i];
    }
    merge_sort(m, 6);
    for (int i = 0; i < 6; i++) {
        CHECK_EQ_INT(m[i], expected[i]);
    }

    int single[] = {42};
    bubble_sort(single, 1);
    CHECK_EQ_INT(single[0], 42);
    merge_sort(single, 0); /* must not crash */

    RETURN_TEST_RESULT();
}
