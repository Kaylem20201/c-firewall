// firewall.c
// Main process

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// TODO: work with env variables instead
#define RULES_FILEPATH "/etc/custom_firewall/current.rules"
#define DISABLED_RULES_FILEPATH "/etc/custom_firewall/accept-all.rules"

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

void load_firewall_rules(char* filepath) {
  char command[64] = "iptables-restore ";
  strcat(command, filepath);
  int res = system(command);
  switch (res) {
  case -1:
    printf("Error -1: Child process error\n");
    break;
  case 127:
    printf("Error 127: Could not execute shell in child process\n");
    break;
  case 0:
    break;
  default:
    printf("Returned %d\n", res);
  }
  exit(res);
}

void enable_firewall() {
  load_firewall_rules(RULES_FILEPATH);
}

void disable_firewall() {
  load_firewall_rules(DISABLED_RULES_FILEPATH);
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
      printf("Disabling firewall...\n");
      disable_firewall();
      break;
    case 'v':
      break;
    case '?':
    default:
      print_help();
    }
  }

  return 0;
}
