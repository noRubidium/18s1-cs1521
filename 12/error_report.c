#include<stdio.h>

void fatal(const char *str) {
  perror(str);
  exit(1);
}
