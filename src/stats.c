#include "stats.h"

#include <stdlib.h>
#include <string.h>

#include "sorting.h"

double stat_mean(const int *a, size_t n) {
    long sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum += a[i];
    }
    return (double)sum / (double)n;
}

double stat_median(const int *a, size_t n) {
    int *copy = (int *)malloc(n * sizeof(int));
    if (copy == NULL) {
        return 0.0;
    }
    memcpy(copy, a, n * sizeof(int));
    merge_sort(copy, n);
    double result;
    if (n % 2 == 1) {
        result = copy[n / 2];
    } else {
        result = (copy[n / 2 - 1] + copy[n / 2]) / 2.0;
    }
    free(copy);
    return result;
}

int stat_max(const int *a, size_t n) {
    int max = a[0];
    for (size_t i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
