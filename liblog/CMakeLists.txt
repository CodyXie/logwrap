option(TARGET_USES_LOGD "Use logd or not." OFF)

if(${TARGET_USES_LOGD})
	set(LIBLOG_SRCS logd_write.c log_event_write.c log_read.c)
else()
	set(LIBLOG_SRCS logd_write_kern.c log_read_kern.c)
endif()

set(LIBLOG_SRCS ${LIBLOG_SRCS} logprint.c event_tag_map.c)
set(LIBLOG_SRCS ${LIBLOG_SRCS} fake_log_device.c)

add_definitions(-DFAKE_LOG_DEVICE=1 -DHAVE_SYS_UIO_H=1 -DHAVE_WRITEV)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(log
    STATIC
    ${LIBLOG_SRCS}
    )
