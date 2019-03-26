#ifndef WANDBOX_GET_PERMLINK_HPP
#define WANDBOX_GET_PERMLINK_HPP
#include <string>

#include <wandbox/compiler.hpp>
#include <wandbox/result.hpp>

namespace wandbox {

struct Permlink_result {
    Result result;
    Compiler compiler;
    std::string code;
};

Permlink_result get_permlink(const std::string& permlink);

}  // namespace wandbox
#endif  // WANDBOX_GET_PERMLINK_HPP
