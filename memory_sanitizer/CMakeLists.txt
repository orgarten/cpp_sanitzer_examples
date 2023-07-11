add_executable(memory_fail memory_fail.cpp)
add_executable(memory_pass memory_pass.cpp)

IF (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    target_compile_options(memory_fail PRIVATE -fsanitize=memory)
    target_link_options(memory_fail PRIVATE -fsanitize=memory)

    target_compile_options(memory_pass PRIVATE -fsanitize=memory)
    target_link_options(memory_pass PRIVATE -fsanitize=memory)
ENDIF()