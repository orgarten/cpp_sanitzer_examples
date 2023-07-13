# Sanitizer Examples for C++ and CMake

This repository provides examples on how to setup the various sanitizers für C++ in CMake. 

The CMake configuration is rather small to focus on setting up the sanitizers. 

I would generally advise everyone to run their projects with sanitizers to minimize errors that might not happen all 
the time. C++ has lot of ways to blow up your application and reducing the surface of error is always a good idea anyway.


**note:** I also suggest to enable all warnings and also enable errors as warning with -Werror to decrease the amount of bugs.

The support for sanitizers seems to be much better for clang, therefore I would suggest running the sanitizers with clang
and if deemed necessary with GCC, too. 

Taking the warnings from the sanitizers seriously is important because they can lead to unforeseen bugs in production and
most of these are nasty to fix.

If not run locally, have them run in a CI for PRs.

One of the downsides of sanitizers is that the error messages are still relatively cryptic, especially compared to the 
ones the Rust compiler gives you.

### ASAN
The address sanitizer (short ASAN) finds typical memory bugs such as

- out-of-bounds access
- use-after-free
- double-free

There is support for some more classes of bugs, but they might be experimental (e.g. memory leaks) or need to be enabled.

These bugs are incredible common in C++, especially in large code bases that have been developed for a long time. The more
memory management is done manually, the more of these bugs will be present.

If an error is detected the program exits with a non-zero code which is what we want to have it run in a CI/CD.

**warning:** ASAN exits on the first error. If multiple errors are in the code you will need to run it multiple times. This might
feel annoying, but it's for the best. 

More information: 
- [LLVM docs](https://clang.llvm.org/docs/AddressSanitizer.html)

### UBSAN
Undefined behavior (UB) is one of the major issues when coding in C++. There are thousands of ways to introduce undefined 
behavior. What's really bad about UB is that it might run perfectly fine on your machine, maybe even on other but sometimes
it just fails. Furthermore, changes in the underlying OS or the hardware architecture will make it explode. 

The main problem is, you never know what will happen when you have UB in your code.

UB should be avoided whenever possible.

Luckily, there is UBSAN, the UndefinedBehaviorSanitizer. 

Some of the things it catches:

- out of bound array access when bounds are static
- bitwise shifts if the shift would make it out of bound for the data type
- signed integer overflow
- conversion between floating point types when destination would overflow.
- devide by zero
- ... 

UBSan is an absolut must in my eyes and should be part of the development cycle for any code!

More info: 
- [Oracle Blog](https://blogs.oracle.com/linux/post/improving-application-security-with-undefinedbehaviorsanitizer-ubsan-and-gcc)
- [LLVM docs](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)

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



