#include <unistd.h>
#include <stdio.h>
#include "error_report.h"

#define MAX_BUFF 300

void print_result(int pipe) {
  // use fork to get none-blocking result reception
}

void prompt(int in, int out) {
  char user_input[MAX_BUFF];
  char op;
  while (1) {
    int err = scanf("%c %s", &op, user_input);
    if (err < 0) fatal("Failed to read stdin");
    switch (op) {
      case 'r':
        // register a new student
        break;
      case 'l':
        // login
        break;
      case 'c':
        if (user_input[0] == 'z') {
          // check enrollment of a student
        } else {
          // check enrollment of a course
        }
      case 'e':
        // enroll in a course for current user
        break;
      case 'q':
        return;
    }
  }
}
