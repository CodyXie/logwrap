#ifndef __ALOG_H__
#define __ALOG_H__


#ifndef __ANDROID__

#define ALOG(level, name, fmt, ...)           \
    do {                                      \
        fprintf (stderr, fmt, ##__VA_ARGS__); \
    } while (0)
#define LOG_INFO 0

#define TEMP_FAILURE_RETRY(exp) ({         \
    __typeof__(exp) _rc;                   \
    do {                                   \
        _rc = (exp);                       \
    } while (_rc == -1 && errno == EINTR); \
    _rc; })
#endif

#endif /* __ALOG_H__ */
