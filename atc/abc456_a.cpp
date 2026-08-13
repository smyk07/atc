/*
 * https://atcoder.jp/contests/abc456/tasks/abc456_a
 */

#include <cstdio>

int x;

int main(void) {

  scanf("%d", &x);

  if (x >= 3 && x <= 18)
    printf("Yes");
  else
    printf("No");

  return 0;
}
