#ifndef WANDBOX_GET_LIST_HPP
#define WANDBOX_GET_LIST_HPP
#include <vector>

#include <wandbox/compiler.hpp>

namespace wandbox {

/// Get the list of compiler's availiable from Wandbox.
/** Throws std::runtime_error if there are issues with connection or request. */
std::vector<Compiler> get_list();

}  // namespace wandbox
#endif  // WANDBOX_GET_LIST_HPP
