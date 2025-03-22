#include "logging.h"

void _lab_log(FILE *file, const char *fmt, ...) {
  va_list args;
  time_t t;
  char datestr[51];

  // print to stderr if no file handle
  if (file == NULL) { file = stderr; }

  //datetime formatting
  t = time(NULL);
  tzset();
  strftime(datestr, sizeof(datestr) -1, "%a %b %d %T %Z %Y", localtime(&t));

  fprintf(file, "%s [%d]: ", datestr, getpid());

  //Write out according to fmt format
  va_start(args, fmt);
  vfprintf(file, fmt, args);
  va_end(args);

  fprintf(file, "\n");
}
