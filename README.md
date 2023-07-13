# Sanitizer Examples for C++ and CMake

This repository provides examples on how to setup the various sanitizers für C++ in CMake. 

The CMake configuration is rather small to focus on setting up the sanitizers. 

I would generally advise everyone to run their projects with sanitizers to minimize errors that might not happen all 
the time. C++ has lot of ways to blow up your application and reducing the surface of error is always a good idea anyway.

##### note
I also suggest to enable all warnings and also enable errors as warning with -Werror to decrease the amount of bugs.

The support for sanitizers seems to be much better for clang, therefore I would suggest running the sanitizers with clang
and if deemed necessary with GCC, too. 

Taking the warnings from the sanitizers seriously is important because they can lead to unforeseen bugs in production and
most of these are nasty to fix.

If not run locally, have them run in a CI for PRs.

### ASAN
The address sanitizer (short ASAN) finds typical memory bugs such as

- out-of-bounds access
- use-after-free
- double-free

There is support for some more classes of bugs, but they might be experimental (e.g. memory leaks) or need to be enabled.

If an error is detected the program exits with a non-zero code which is what we want to have it run in a CI/CD.

##### warning
ASAN exits on the first error. If multiple errors are in the code you will need to run it multiple times. This might
feel annoying but it's for the best. 

More information: [llvm docs](https://clang.llvm.org/docs/AddressSanitizer.html)

### UBSAN

### Thread Sanitizer

### Memory Sanitizer

### Leak Sanitizer



## Compiler Support

The following table shows which sanitizers are support by the individual compilers.

| Sanitizer          | flag                   | GCC | Clang |
|--------------------|------------------------|-----|-------|
| Address            | `-fsanitize=address`   | ✅   | ✅     |
| Thread             | `-fsanitize=thread`    | ✅   | ✅     |
| Memory             | `-fsanitize=memory`    | ❌   | ✅     |
| Undefined Behavior | `-fsanitize=undefined` | ✅   | ✅     |



