add_executable(thread_fail thread_fail.cpp)

#target_compile_options(thread_fail PRIVATE -fsanitize=thread)
#target_link_options(thread_fail PRIVATE -fsanitize=thread)
