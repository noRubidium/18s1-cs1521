#include <assert.h>

int myStrCmp(char *a, char *b);

int main() {
  assert(myStrCmp("a", "b") == -1);
  assert(myStrCmp("a", "a") == 0);
  assert(myStrCmp("a", "aa") == -1);
  assert(myStrCmp("b", "a") == 1);

  return 0;
}

int myStrCmp(char *a, char *b) {
  return 0;
}
