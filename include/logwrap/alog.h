#ifndef __ALOG_H__
#define __ALOG_H__

#include <log/log.h>

#ifndef __ANDROID__

#define TEMP_FAILURE_RETRY(exp) ({         \
    __typeof__(exp) _rc;                   \
    do {                                   \
        _rc = (exp);                       \
    } while (_rc == -1 && errno == EINTR); \
    _rc; })
#endif

#endif /* __ALOG_H__ */
