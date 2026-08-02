/*
 * https://atcoder.jp/contests/abc453/tasks/abc453_a
 */

#include <cstdio>
#include <print>

int n;

char buf[50];
char *p = buf;

int main(void) {
  scanf("%d %s", &n, buf);

  while (*p == 'o')
    p++;

  std::print("{}", p);

  return 0;
}
