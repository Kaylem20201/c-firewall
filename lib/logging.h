#ifndef _LABLIB_LOGGING_H

#define _LABLIB_LOGGING_H

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>

void _lab_log(FILE *file, const char *fmt, ...);

#define lab_logf(f, ...) _lab_log(f, __VA_ARGS__)
#define lab_log(...) _lab_log(NULL, __VA_ARGS__)

#endif /* logging.h */
