/*
 * https://atcoder.jp/contests/abc450/tasks/abc450_a
 */

#include <stdio.h>

int n;

int main(void) {
  scanf("%d", &n);

  for (; n > 1; --n) {
    printf("%d,", n);
  }
  printf("%d", n);

  return 0;
}
