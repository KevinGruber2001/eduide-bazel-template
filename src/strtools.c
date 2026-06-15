#include "strtools.h"

#include <ctype.h>
#include <string.h>

int str_word_count(const char *s) {
    int count = 0;
    int in_word = 0;
    for (const char *p = s; *p != '\0'; p++) {
        if (isspace((unsigned char)*p)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }
    return count;
}

size_t str_reverse_words(const char *s, char *out, size_t out_size) {
    size_t len = strlen(s);
    if (out_size == 0) {
        return (size_t)-1;
    }
    out[0] = '\0';
    size_t written = 0;

    /* Walk the string from the end, emitting each word as we find its start. */
    size_t i = len;
    while (i > 0) {
        /* skip trailing whitespace */
        while (i > 0 && isspace((unsigned char)s[i - 1])) {
            i--;
        }
        if (i == 0) {
            break;
        }
        size_t end = i;
        while (i > 0 && !isspace((unsigned char)s[i - 1])) {
            i--;
        }
        size_t word_len = end - i;
        size_t need = written + (written > 0 ? 1 : 0) + word_len;
        if (need + 1 > out_size) {
            return (size_t)-1;
        }
        if (written > 0) {
            out[written++] = ' ';
        }
        memcpy(out + written, s + i, word_len);
        written += word_len;
        out[written] = '\0';
    }
    return written;
}
