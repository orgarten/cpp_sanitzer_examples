add_executable(memory_fail memory_fail.cpp)

IF (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    target_compile_options(memory_fail PRIVATE -fsanitize=memory)
    target_link_options(memory_fail PRIVATE -fsanitize=memory)
ENDIF()