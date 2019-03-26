add_library(wandbox STATIC
    compile.cpp
    get_list.cpp
    get_permlink.cpp
    get_template.cpp
    detail/get_connection.cpp
    detail/to_string.cpp
    detail/to_result.cpp
    detail/to_session.cpp
    detail/to_compiler.cpp
)

target_link_libraries(wandbox HTTP_lib)
target_compile_features(wandbox PRIVATE cxx_std_17)
target_compile_options(wandbox PRIVATE -Wall -Wextra)
target_include_directories(wandbox PUBLIC ${PROJECT_SOURCE_DIR}/include/)
