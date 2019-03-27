# Wandbox RESTful API

This library provides access to the [Wandbox](https://wandbox.org) REST API.
Depends on Boost Asio, Boost Property Tree, and my HTTP library.

```cpp
#include <wandbox/compile.hpp>
#include <wandbox/get_list.hpp>
#include <wandbox/get_permlink.hpp>
#include <wandbox/get_template.hpp>
#include <wandbox/session.hpp>

int main() {
    // Create a Session
    wandbox::Session context;
    context.name = "gcc-head";
    context.options = "-O3, -std=c++17";
    
    // Compile Code
    const std::string code =
        "#include <iostream>\nint main(){std::cout << \"Hello, "
        "World!\\n\";\nreturn 1;\n}";
    auto result = wandbox::compile(context, code);
    assert(result.program_stdout == "Hello, World!");
    
    // Get List of Compilers
    auto list = wandbox::get_list();
    for (const auto& compiler : list) {
        std::cout << compiler.display_name << '\n';
    }
    
    // Get permlink Session, Code, and Result
    auto result2 = wandbox::get_permlink("GPKsvV34hXIPUzxt");
    std::cout << result2.code << '\n';
    
    // Get Code from Template Name
    std::cout << wandbox::get_template("mono") << '\n';
    
    return 0;
}
```

## Build Instructions
```
git clone https://github.com/a-n-t-h-o-n-y/wandbox-lib.git
mkdir wandbox-lib/build && cd wandbox-lib/build
git submodule update --init --recursive   # Pull in dependencies
cmake -DCMAKE_BUILD_TYPE=Release ..       # Generate Makefiles
make                                      # Build library
```
