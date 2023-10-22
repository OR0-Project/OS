# Building

The kernel uses GNU make as its build system.

You can find the build recipes at `kernel/src/Makefile`.

## Generating a build

Simply run `make all` to generate a new kernel build and accompanying ISO file.

When complete, you can find the built kernel in `cdrom/sys/kernel_*` and the ISO file at `build/os.iso`.

## What now?

Test, of course :) and maybe give some feedback.

## Appendix: Makefile recipes

This section outlines the most important Makefile recipes and what they do.

### clean

This recipe cleans up all build artifacts (built binaries, object files, etc.)

### prep

This recipe sets up the necessary directory structure for the build (obj/, build/, etc).

The recipe also generates a build header (`build.h`) file, which contains information specific to the build being generated (commit hash, build date). The kernel uses this file to tell the user what build of the kernel they're running.

### all

Builds the kernel and an accompanying kernel ISO file.

### iso-test

Runs `all` and opens a QEMU window where a developer can test their kernel build, which is important for rapid testing and development.

If you want to run this kernel on physical hardware, consult the README.md document in the root of this Git repository.
