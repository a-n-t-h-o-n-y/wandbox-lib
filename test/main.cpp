#include <iostream>

#include <wandbox/compile.hpp>
#include <wandbox/compiler.hpp>
#include <wandbox/detail/get_connection.hpp>
#include <wandbox/detail/to_string.hpp>
#include <wandbox/get_list.hpp>
#include <wandbox/get_permlink.hpp>
#include <wandbox/get_template.hpp>

int main() {
    auto context = wandbox::Compiler{};
    context.name = "gcc-head";
    context.options = "-O3, -std=c++17";
    context.save = true;
    const std::string code =
        R"(#include <iostream>\nint main(){std::cout << \"Hello, World!\\n\";\nreturn 1;\n})";
    auto result = wandbox::compile(context, code);
    std::cout << wandbox::detail::to_string(result) << '\n';

    auto list = wandbox::get_list();
    // for (const auto& compiler_info : list) {
    //     std::cout << wandbox::detail::to_string(compiler_info) << '\n';
    // }

    auto result2 = wandbox::get_permlink("GPKsvV34hXIPUzxt");
    std::cout << wandbox::detail::to_string(result2.result) << '\n';
    std::cout << result2.code << '\n';
    std::cout << wandbox::get_template("mono") << '\n';

    wandbox::detail::get_connection().lowest_layer().close();

    return 0;
}
