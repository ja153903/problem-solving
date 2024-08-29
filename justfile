setup-compile-commands:
  bazel run @hedron_compile_commands//:refresh_all

run BINARY:
  bazel build //main:{{BINARY}} && bazel-bin/main/{{BINARY}}

