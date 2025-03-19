// daemon.c
// Spawns a daemon for ongoing processes

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int _daemon() {
  pid_t pID = fork();
  if (pID < 0) {
    exit(EXIT_FAILURE);
  }
  if (pID > 0) {
    exit(EXIT_SUCCESS);
  }
  return 0;
}
