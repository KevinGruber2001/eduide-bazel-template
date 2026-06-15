#include "stats.h"

#include <math.h>

#include "check.h"

int main(void) {
    int data[] = {5, 3, 8, 1, 9, 2};

    CHECK(fabs(stat_mean(data, 6) - 28.0 / 6.0) < 1e-9);
    CHECK(fabs(stat_median(data, 6) - 4.0) < 1e-9);
    CHECK_EQ_INT(stat_max(data, 6), 9);

    RETURN_TEST_RESULT();
}
