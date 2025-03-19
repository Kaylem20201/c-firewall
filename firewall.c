// firewall.c
// Main process

#include <stdio.h>
#include <unistd.h>

void print_help() {
  int long_flag_width = 32;
  int commands_width = 64;

  printf("Usage: firewall [OPTION]\n");
  printf("Configure the custom firewall.\n");
  printf("Commands: \n");
  printf("  -l, %*s%*s\n", long_flag_width, "--logs", commands_width,
         "Print firewall logs to stdout");
  printf("  -e, %*s%*s\n", long_flag_width, "--enable", commands_width,
         "Enable firewall");
  printf("  -d, %*s%*s\n", long_flag_width, "--disable", commands_width,
         "Disable firewall");
  printf("  -v, %*s%*s\n", long_flag_width, "--version", commands_width,
         "Display version information");
}

int main(int argc, char **argv) {

  int opt;
  while ((opt = getopt(argc, argv, "ledv:") != -1)) {
    switch (opt) {
    default:
      print_help();
    }
  }

  return 0;
}
