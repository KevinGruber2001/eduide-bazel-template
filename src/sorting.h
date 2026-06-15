#ifndef EDUIDE_SORTING_H
#define EDUIDE_SORTING_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Sorts the array of n ints ascending, in place, using bubble sort. */
void bubble_sort(int *a, size_t n);

/* Sorts the array of n ints ascending, in place, using merge sort. */
void merge_sort(int *a, size_t n);

#ifdef __cplusplus
}
#endif

#endif /* EDUIDE_SORTING_H */
