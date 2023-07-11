add_executable(memory_fail memory_fail.cpp)
target_compile_options(memory_fail PRIVATE -fsanitize=memory)
target_link_options(memory_fail PRIVATE -fsanitize=memory)


add_executable(memory_pass memory_pass.cpp)
target_compile_options(memory_pass PRIVATE -fsanitize=memory)
target_link_options(memory_pass PRIVATE -fsanitize=memory)
