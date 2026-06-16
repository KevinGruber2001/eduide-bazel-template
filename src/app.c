#include <stdio.h>

#include "gen.h"
#include "sorting.h"
#include "stats.h"
#include "strtools.h"

int main(void) {
    int data[] = {5, 3, 8, 1, 9, 2};
    size_t n = sizeof(data) / sizeof(data[0]);

    int sorted[6];
    for (size_t i = 0; i < n; i++) {
        sorted[i] = data[i];
    }
    merge_sort(sorted, n);

    printf("sorted   =");
    for (size_t i = 0; i < n; i++) {
        printf(" %d", sorted[i]);
    }
    printf("\n");

    printf("median   = %.1f\n", stat_median(data, n));
    printf("max      = %d\n", stat_max(data, n));

    char reversed[64];
    str_reverse_words("the quick brown fox", reversed, sizeof(reversed));
    printf("reversed = %s\n", reversed);
    printf("words    = %d\n", str_word_count("the quick brown fox"));
    printf("gen      = %ld\n", eduide_gen_total(data[0]));

    return 0;
}
