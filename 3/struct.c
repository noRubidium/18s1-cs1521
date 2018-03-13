#include <stdio.h>

typedef struct _node1 Node1;
struct _node1 {
   Node1 *next;
   char *str;
};
typedef struct _node2 Node2;
struct _node2 {
   Node2 *next;
   char str[100];
};
typedef struct _node3 Node3;
struct _node3 {
   Node3 *next;
   char str[1];
};

int main () {
  printf("Node 1: %lu", sizeof(Node1 *));
  printf("Node 2: %lu", sizeof(Node2 *));
  printf("Node 3: %lu", sizeof(Node3 *));

  return 0;
}
