
//
// Copyright 2005 The Android Open Source Project
//
// C/C++ logging functions.  See the logging documentation for API details.
//
// We'd like these to be available from C code (in case we import some from
// somewhere), so this has a C interface.
//
// The output will be correct when the log file is shared between multiple
// threads and/or multiple processes so long as the operating system
// supports O_APPEND.  These calls have mutex-protected data structures
// and so are NOT reentrant.  Do not use LOG in a signal handler.
//
#ifndef _MINZIP_LOG_H
#define _MINZIP_LOG_H

#include <stdio.h>

// ---------------------------------------------------------------------

#ifndef LOG_NDEBUG
#ifdef NDEBUG
#define LOG_NDEBUG 1
#else
#define LOG_NDEBUG 0
#endif
#endif

#ifndef LOG_TAG
#define LOG_TAG NULL
#endif

// ---------------------------------------------------------------------

#ifndef LOGV
#if LOG_NDEBUG
#define LOGV(...)   ((void)0)
#else
#define LOGV(...) ((void)LOG(LOG_VERBOSE, LOG_TAG, __VA_ARGS__))
#endif
#endif

#define CONDITION(cond)     (__builtin_expect((cond)!=0, 0))

#ifndef LOGV_IF
#if LOG_NDEBUG
#define LOGV_IF(cond, ...)   ((void)0)
#else
#define LOGV_IF(cond, ...) \
    ( (CONDITION(cond)) \
    ? ((void)LOG(LOG_VERBOSE, LOG_TAG, __VA_ARGS__)) \
    : (void)0 )
#endif
#endif

#define LOGVV LOGV
#define LOGVV_IF LOGV_IF

#ifndef LOGD
#define LOGD(...) ((void)LOG(LOG_DEBUG, LOG_TAG, __VA_ARGS__))
#endif

#ifndef LOGD_IF
#define LOGD_IF(cond, ...) \
    ( (CONDITION(cond)) \
    ? ((void)LOG(LOG_DEBUG, LOG_TAG, __VA_ARGS__)) \
    : (void)0 )
#endif

#ifndef LOGI
#define LOGI(...) ((void)LOG(LOG_INFO, LOG_TAG, __VA_ARGS__))
#endif

#ifndef LOGI_IF
#define LOGI_IF(cond, ...) \
    ( (CONDITION(cond)) \
    ? ((void)LOG(LOG_INFO, LOG_TAG, __VA_ARGS__)) \
    : (void)0 )
#endif

#ifndef LOGW
#define LOGW(...) ((void)LOG(LOG_WARN, LOG_TAG, __VA_ARGS__))
#endif

#ifndef LOGW_IF
#define LOGW_IF(cond, ...) \
    ( (CONDITION(cond)) \
    ? ((void)LOG(LOG_WARN, LOG_TAG, __VA_ARGS__)) \
    : (void)0 )
#endif

#ifndef LOGE
#define LOGE(...) ((void)LOG(LOG_ERROR, LOG_TAG, __VA_ARGS__))
#endif

#ifndef LOGE_IF
#define LOGE_IF(cond, ...) \
    ( (CONDITION(cond)) \
    ? ((void)LOG(LOG_ERROR, LOG_TAG, __VA_ARGS__)) \
    : (void)0 )
#endif


#ifndef IF_LOGV
#if LOG_NDEBUG
#define IF_LOGV() if (false)
#else
#define IF_LOGV() IF_LOG(LOG_VERBOSE, LOG_TAG)
#endif
#endif

#ifndef IF_LOGD
#define IF_LOGD() IF_LOG(LOG_DEBUG, LOG_TAG)
#endif

#ifndef IF_LOGI
#define IF_LOGI() IF_LOG(LOG_INFO, LOG_TAG)
#endif

#ifndef IF_LOGW
#define IF_LOGW() IF_LOG(LOG_WARN, LOG_TAG)
#endif

#ifndef IF_LOGE
#define IF_LOGE() IF_LOG(LOG_ERROR, LOG_TAG)
#endif

// ---------------------------------------------------------------------

#ifndef LOG
#define LOG(priority, tag, ...) \
    LOG_PRI(ANDROID_##priority, tag, __VA_ARGS__)
#endif

#ifndef LOG_PRI
#define LOG_PRI(priority, tag, ...) \
    printf(tag ": " __VA_ARGS__)
#endif

#ifndef IF_LOG
#define IF_LOG(priority, tag) \
    if (1)
#endif

#endif // _MINZIP_LOG_H
