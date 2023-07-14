add_executable(ubsan_fail ubsan_fail.cpp)


#IF (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
#    target_compile_options(ubsan_fail PRIVATE -fsanitize=undefined,float-divide-by-zero,unsigned-integer-overflow,local-bounds,implicit-conversion)
#    target_link_options(ubsan_fail PRIVATE -fsanitize=undefined,float-divide-by-zero,unsigned-integer-overflow,local-bounds,implicit-conversion)
#ELSE ()
#    target_compile_options(ubsan_fail PRIVATE -fsanitize=undefined)
#    target_link_options(ubsan_fail PRIVATE -fsanitize=undefined)
#ENDIF()