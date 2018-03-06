// Bracket matcher
// COMP1521 18s1

#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

void fatal(char *);

int main(void)
{
   Stack brackets;  // uninitialized bracket Stack
   int   ch;        // current character

   initStack(&brackets);
   while ((ch = getchar()) != EOF) {
      if (ch == '(' || ch == '{' || ch == '[') {
         if (!pushStack(&brackets, ch))
            fatal("Too much nesting");
         showStack(brackets);
      }
      else if (ch == ')') {
         if (popStack(&brackets) != '(')
            fatal("Mismatch on (..)");
      }
      else if (ch == '}') {
         if (popStack(&brackets) != '{')
            fatal("Mismatch on {..}");
      }
      else if (ch == ']') {
         if (popStack(&brackets) != '[')
            fatal("Mismatch on [..]");
      }
   }
   if (!isEmptyStack(brackets))
      fatal("Insufficient closing brackets");
   printf("OK\n");
   return 0;
}

void fatal(char *msg)
{
   printf("%s\n", msg);
   exit(1);
}
