CMAKE_MINIMUM_REQUIRED(VERSION 3.24)
project(sanitzer_examples
        VERSION 1.0.0
        DESCRIPTION "A collection of examples for sanitizers."
        LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(address_sanitizer)
add_subdirectory(memory_sanitizer)
add_subdirectory(undefined_behavior_sanitizer)
add_subdirectory(thread_sanitizer)