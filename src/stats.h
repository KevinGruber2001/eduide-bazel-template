#ifndef EDUIDE_STATS_H
#define EDUIDE_STATS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Arithmetic mean of n values (n must be > 0). */
double stat_mean(const int *a, size_t n);

/* Median of n values; sorts an internal copy, leaving a unchanged. */
double stat_median(const int *a, size_t n);

/* Maximum of n values (n must be > 0). */
int stat_max(const int *a, size_t n);

#ifdef __cplusplus
}
#endif

#endif /* EDUIDE_STATS_H */
