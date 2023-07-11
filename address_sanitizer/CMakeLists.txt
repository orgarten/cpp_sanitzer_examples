add_executable(asan_fail asan_fail.cpp)
target_compile_options(asan_fail PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(asan_fail PRIVATE -fsanitize=address -fno-omit-frame-pointer)

set_target_properties(asan_fail PROPERTIES LINKER_LANGUAGE CXX)

add_executable(asan_pass asan_pass.cpp)
target_compile_options(asan_pass PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(asan_pass PRIVATE -fsanitize=address -fno-omit-frame-pointer)

set_target_properties(asan_pass PROPERTIES LINKER_LANGUAGE CXX)
