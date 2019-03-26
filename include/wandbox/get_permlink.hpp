#ifndef WANDBOX_GET_PERMLINK_HPP
#define WANDBOX_GET_PERMLINK_HPP
#include <string>

#include <wandbox/result.hpp>
#include <wandbox/session.hpp>

namespace wandbox {

/// Data returned by requesting a permlink to a specific compilation.
struct Permlink_result {
    Result result;
    Session context;
    std::string code;
};

Permlink_result get_permlink(const std::string& permlink);

}  // namespace wandbox
#endif  // WANDBOX_GET_PERMLINK_HPP
