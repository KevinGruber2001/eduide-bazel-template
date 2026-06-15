#include "strtools.h"

#include <string.h>

#include "check.h"

int main(void) {
    CHECK_EQ_INT(str_word_count("the quick brown fox"), 4);
    CHECK_EQ_INT(str_word_count("   spaced   out  "), 2);
    CHECK_EQ_INT(str_word_count(""), 0);

    char out[64];
    size_t n = str_reverse_words("the quick brown fox", out, sizeof(out));
    CHECK(n != (size_t)-1);
    CHECK(strcmp(out, "fox brown quick the") == 0);

    char small[4];
    CHECK(str_reverse_words("the quick brown fox", small, sizeof(small)) ==
          (size_t)-1);

    RETURN_TEST_RESULT();
}
