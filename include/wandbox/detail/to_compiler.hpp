#ifndef WANDBOX_DETAIL_TO_COMPILER_HPP
#define WANDBOX_DETAIL_TO_COMPILER_HPP
#include <boost/property_tree/ptree.hpp>

#include <wandbox/compiler.hpp>

namespace wandbox {
namespace detail {

Compiler to_compiler(const boost::property_tree::ptree& tree);

}  // namespace detail
}  // namespace wandbox
#endif  // WANDBOX_DETAIL_TO_COMPILER_HPP
