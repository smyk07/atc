/*
 * https://atcoder.jp/contests/abc456/tasks/abc455_a
 */

#include <cstdio>

int a, b, c;

int main(void) {

  scanf("%d %d %d", &a, &b, &c);

  if (a != b && b == c)
    printf("Yes");
  else
    printf("No");

  return 0;
}
