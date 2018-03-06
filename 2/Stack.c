#include<stdio.h>
#include "Stack.h"

void initStack(Stack *s) {
  s->top = 0;
}

int  pushStack(Stack *s, Item val) {
  if (s->top >= MAX_STACK - 1) return 0;
  s->items[s->top++] = val;
  return 1;
}

Item popStack(Stack *s) {
  return s->items[--s->top];
}

int isEmptyStack(Stack s) {
  return s.top == 0;
}

void showStack(Stack s) {
  for (int i = 0; i < s.top; ++i) {
    printf("%c -> ", s.items[i]);
  }
  printf("X\n");
}
