# EduIDE Bazel Benchmark Template

The **Bazel workload** for the EduIDE shared build-cache evaluation: a small C
project built and tested with Bazel. It is deliberately a *different language
and build system* from the Gradle template (`eduide-gradle-template`), which
mirrors the thesis goal of generalising the shared cache beyond Gradle/Java. The
two are kept comparable in size (same algorithms: sorting, statistics, string
tools).

## Why this shape
- **C + Bazel** exercises a fundamentally different toolchain (compile + link of
  C objects) and Bazel's **action-level** caching, which is the property the
  evaluation highlights against Gradle's coarser task-level caching.
- **No external dependencies.** The EduIDE C blueprint ships a *C-only*
  toolchain (no C++ / `cc1plus`), so tests use a tiny pure-C harness
  (`test/check.h`) instead of GoogleTest. The dependency-proxy part of the
  evaluation is covered by the Gradle/Maven template instead.
- **Per-file `cc_test` targets** so an edit reruns only the affected test action,
  making fine-grained cache reuse visible (used for the Bazel reuse experiment).
- `sorting.c` is the dependency-free edit target for incremental builds.

## Layout
```
MODULE.bazel                bzlmod module (no external deps)
src/BUILD.bazel             :eduide cc_library, :app cc_binary
src/{sorting,stats,strtools}.{c,h}, app.c
test/BUILD.bazel            :check helper + one cc_test per *_test.c
test/check.h, test/{sorting,stats,strtools}_test.c   pure-C tests
```

## Build
```bash
bazel build //...
bazel test  //...
# with the shared remote cache (no auth while disabled):
bazel build //... --remote_cache=http://eduide-shared-cache.<ns>.svc.cluster.local:8080/bazel/
```
Bazel 7.4.1 (pinned in `.bazelversion`); needs a local **C** toolchain (present
in the EduIDE C blueprint).

## Use in the benchmark harness (theia-scale-tests)
```
BENCH_BUILD_SYSTEM=bazel
BENCH_TARGET_APP=<c blueprint id>     # e.g. c-templates on test2
BENCH_REPO_URL=<git url of this template>
BENCH_EDIT_FILE=src/sorting.c
```

This template is referenced in the thesis as the representative Bazel workload.
