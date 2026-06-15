#ifndef EDUIDE_STRTOOLS_H
#define EDUIDE_STRTOOLS_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Number of whitespace-separated words in s. */
int str_word_count(const char *s);

/*
 * Writes the words of s in reverse order into out (space-separated, NUL
 * terminated). Returns the length written, or (size_t)-1 if out is too small.
 */
size_t str_reverse_words(const char *s, char *out, size_t out_size);

#ifdef __cplusplus
}
#endif

#endif /* EDUIDE_STRTOOLS_H */
