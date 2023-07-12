add_executable(asan_fail asan_fail.cpp)
target_compile_options(asan_fail PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(asan_fail PRIVATE -fsanitize=address -fno-omit-frame-pointer)
