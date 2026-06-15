#include "sorting.h"

#include <stdlib.h>
#include <string.h>

/*
 * Dependency-free sorting algorithms.
 *
 * This file is the ideal edit target for the build-cache benchmark: changing it
 * invalidates only the actions that compile and depend on it, which is exactly
 * the granularity we want to measure.
 */

void bubble_sort(int *a, size_t n) {
    if (n < 2) {
        return;
    }
    for (size_t i = 0; i + 1 < n; i++) {
        int swapped = 0;
        for (size_t j = 0; j + 1 < n - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

static void merge(int *a, size_t lo, size_t mid, size_t hi, int *buf) {
    size_t i = lo;
    size_t j = mid;
    size_t k = lo;
    while (i < mid && j < hi) {
        buf[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    while (i < mid) {
        buf[k++] = a[i++];
    }
    while (j < hi) {
        buf[k++] = a[j++];
    }
    memcpy(a + lo, buf + lo, (hi - lo) * sizeof(int));
}

static void merge_sort_rec(int *a, size_t lo, size_t hi, int *buf) {
    if (hi - lo < 2) {
        return;
    }
    size_t mid = lo + (hi - lo) / 2;
    merge_sort_rec(a, lo, mid, buf);
    merge_sort_rec(a, mid, hi, buf);
    merge(a, lo, mid, hi, buf);
}

void merge_sort(int *a, size_t n) {
    if (n < 2) {
        return;
    }
    int *buf = (int *)malloc(n * sizeof(int));
    if (buf == NULL) {
        return;
    }
    merge_sort_rec(a, 0, n, buf);
    free(buf);
}
