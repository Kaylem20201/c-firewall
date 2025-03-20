// firewall.c
// Main process

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// TODO: work with env variables instead
#define RULES_FILEPATH "/etc/custom_firewall/current.rules"

void print_help() {
  int long_flag_width = 16;
  int commands_width = 32;

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
  char command[64] = "iptables-restore ";
  strcat(command, RULES_FILEPATH);
  int res = system(command);
  switch (res) {
  case -1:
    printf("Error -1: Child process error\n");
  case 127:
    printf("Error 127: Could not execute shell in child process\n");
  case 0:
    return;
  default:
    printf("Returned %d\n", res);
  }
}

int main(int argc, char **argv) {

  int opt;
  while ((opt = getopt(argc, argv, "ledv")) != -1) {
    switch (opt) {
    case 'l':
      break;
    case 'e':
      printf("Enabling firewall...\n");
      enable_firewall();
      break;
    case 'd':
    case 'v':
      break;
    case '?':
    default:
      print_help();
    }
  }

  return 0;
}
