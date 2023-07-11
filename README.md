# Sanitizer Examples for C++ and CMake

This repository provides examples on how to setup the various sanitizers für C++ in CMake. 

The CMake configuration is rather small to focus on setting up the sanitizers. 

I would generally advise everyone to run their projects with sanitizers to minimize errors that might not happen all 
the time. C++ has lot of ways to blow up your application and reducing the surface of error is always a good idea anyway.

!!! note
   
    I also suggest to enable all warnings and also enable errors as warning with -Werror to decrease the amount of bugs.

The support for sanitizers seems to be much better for clang, therefore I would suggest running the sanitizers with clang
and if deemed necessary with GCC, too. 

Taking the warnings from the sanitizers seriously is important because they can lead to unforeseen bugs in production and
most of these are nasty to fix.

If not run locally, have them run in a CI for PRs.

## Compiler Support

The following table shows which sanitizers are support by the individual compilers.

| Sanitizer          | flag                   | GCC | Clang |
|--------------------|------------------------|-----|-------|
| Address            | `-fsanitize=address`   | ✅   | ✅     |
| Thread             | `-fsanitize=thread`    | ✅   | ✅     |
| Memory             | `-fsanitize=memory`    | ❌   | ✅     |
| Undefined Behavior | `-fsanitize=undefined` | ✅   | ✅     |


