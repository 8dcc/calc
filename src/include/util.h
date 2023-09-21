#ifndef UTIL_H_
#define UTIL_H_

#include <stdio.h>
#include <stdarg.h> /* va_list */
#include "color.h"

static inline void err_msg(const char* fmt, ...) {
    va_list va;
    va_start(va, fmt);

#ifdef USE_COLOR
    fprintf(stderr, COL_ERROR);
#endif

    vfprintf(stderr, fmt, va);

#ifdef USE_COLOR
    fprintf(stderr, COL_NORM "\n");
#else
    fprintf(stderr, "\n");
#endif

    va_end(va);
}

#endif /* UTIL_H_ */
