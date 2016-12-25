project(log)

cmake_minimum_required(VERSION 2.8)
set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)

add_definitions(-DFAKE_LOG_DEVICE -DHAVE_SYS_UIO_H=1)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LIBLOG_SRCS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(log
    STATIC
    ${LIBLOG_SRCS}
    )
