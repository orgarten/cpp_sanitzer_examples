add_executable(ubsan_fail ubsan_fail.cpp)
add_executable(ubsan_pass ubsan_pass.cpp)


IF (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    target_compile_options(ubsan_fail PRIVATE -fsanitize=undefined,float-divide-by-zero,unsigned-integer-overflow,local-bounds,implicit-conversion)
    target_link_options(ubsan_fail PRIVATE -fsanitize=undefined,float-divide-by-zero,unsigned-integer-overflow,local-bounds,implicit-conversion)

    target_compile_options(ubsan_pass PRIVATE -fsanitize=undefined)
    target_link_options(ubsan_pass PRIVATE -fsanitize=undefined)
ELSE ()
    target_compile_options(ubsan_fail PRIVATE -fsanitize=undefined)
    target_link_options(ubsan_fail PRIVATE -fsanitize=undefined)
ENDIF()