// Bracket matcher
// COMP1521 18s1

#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

void fatal(char *);

int main(void)
{
  char c;
  Stack s;

  initStack(&s);

  while ((c = getchar()) != EOF) {
    if (c == '{'|| c == '[' || c == '(') {
      pushStack(&s, c);
    } else if (c == '}') {
      char last = popStack(&s);
      if (last != '{') {
        fatal("Non-matching }");
      }
    } else if (c == ']') {
      char last = popStack(&s);
      if (last != '[') {
        fatal("Non-matching ]");
      }
    } else if (c == ')') {
      char last = popStack(&s);
      if (last != '(') {
        fatal("Non-matching )");
      }
    }
  }
  if (!isEmptyStack(s)) {
    fatal("ERRRRRRR");
  }
  
  printf("YAY!\n");
  return 0;
}

void fatal(char *msg)
{
   printf("%s\n", msg);
   exit(1);
}
