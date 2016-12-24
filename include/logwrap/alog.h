#ifndef __ALOG_H__
#define __ALOG_H__

#include "libc_logging.h"

#ifndef __ANDROID__

#define ALOG_STDERR(level, name, fmt, ...)           \
    do {                                      \
        fprintf (stderr, fmt, ##__VA_ARGS__); \
    } while (0)

#define ALOG_BIONIC(level, name, fmt, ...)           \
    do {                                      \
        __libc_format_log(level, name, fmt, ##__VA_ARGS__); \
    } while (0)

#define ALOG(level, name, fmt, ...) ALOG_BIONIC(level, name, fmt, ##__VA_ARGS__)

#define LOG_INFO  ANDROID_LOG_INFO
#define LOG_ERROR ANDROID_LOG_ERROR

#define TEMP_FAILURE_RETRY(exp) ({         \
    __typeof__(exp) _rc;                   \
    do {                                   \
        _rc = (exp);                       \
    } while (_rc == -1 && errno == EINTR); \
    _rc; })
#endif

#endif /* __ALOG_H__ */
