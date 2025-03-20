// firewall.c
// Main process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define RULES_FILEPATH "/etc/iptables/custom_firewall.rules"

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

void enable_firewall() {
  char command[] = "iptables-restore ";
  strcat(command, RULES_FILEPATH);
  int res = system(command);
  switch (res) {
    case -1:
      printf("Error -1: Child process error");
    case 127:
      printf("Error 127: Could not execute shell in child process");
    case 0:
      return;
    default:
      printf("Returned %d", res);
  }
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
