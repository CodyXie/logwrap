#ifndef __LOG_API_H__
#define __LOG_API_H__

#define LOG_API __attribute__ ((visibility ("default")))

#ifndef __ANDROID__
#include <log/log.h>
#include <logwrap/logwrap.h>
#endif

#define os_fork_execvp_ext android_fork_execvp_ext

#endif /* __LOG_API_H__ */
