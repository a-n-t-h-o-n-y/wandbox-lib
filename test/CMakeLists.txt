add_executable(test EXCLUDE_FROM_ALL main.cpp)
target_compile_features(test PRIVATE cxx_std_17)
target_compile_options(test PRIVATE -Wall -Wextra)

target_link_libraries(test wandbox)
