#ifndef EDUIDE_TEST_CHECK_H
#define EDUIDE_TEST_CHECK_H

#include <stdio.h>

/*
 * Tiny pure-C test helper. The C blueprint ships a C-only toolchain (no C++),
 * so the tests avoid GoogleTest and instead use a main() that returns non-zero
 * on failure, which Bazel's cc_test reports as a failing test.
 */

static int eduide_test_failures = 0;

#define CHECK(cond)                                                        \
    do {                                                                   \
        if (!(cond)) {                                                     \
            fprintf(stderr, "CHECK failed: %s (%s:%d)\n", #cond, __FILE__, \
                    __LINE__);                                             \
            eduide_test_failures++;                                        \
        }                                                                  \
    } while (0)

#define CHECK_EQ_INT(a, b)                                                   \
    do {                                                                     \
        long _va = (long)(a);                                                \
        long _vb = (long)(b);                                                \
        if (_va != _vb) {                                                    \
            fprintf(stderr, "CHECK_EQ failed: %s=%ld != %s=%ld (%s:%d)\n",   \
                    #a, _va, #b, _vb, __FILE__, __LINE__);                   \
            eduide_test_failures++;                                          \
        }                                                                    \
    } while (0)

#define RETURN_TEST_RESULT() return eduide_test_failures == 0 ? 0 : 1

#endif /* EDUIDE_TEST_CHECK_H */
