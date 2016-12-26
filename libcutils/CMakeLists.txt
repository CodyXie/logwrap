
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIBCUTILS_SRCS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(android_cutils
    STATIC
    ${LIBCUTILS_SRCS}
    )
