project(utils)

cmake_minimum_required(VERSION 2.8)
set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIBUTILS_SRCS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(utils
    STATIC
    ${LIBUTILS_SRCS}
    )
