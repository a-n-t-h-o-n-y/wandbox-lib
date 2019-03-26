cmake_minimum_required(VERSION 3.2)
project(wandbox_lib)

add_subdirectory(external/HTTP_Library)
add_subdirectory(src)
add_subdirectory(test)

# DOXYGEN
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
find_package(Doxygen)
if(DOXYGEN_FOUND)
    add_custom_target(docs
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile
        WORKING_DIRECTORY
            ${CMAKE_CURRENT_SOURCE_DIR}/docs
        COMMENT
            "Generating API documentation with Doxygen" VERBATIM)
endif()

