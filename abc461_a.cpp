/*
 * https://atcoder.jp/contests/abc461/tasks/abc461_a
 */

#include <cstdio>
#include <print>

int a, d;

int main(void) {
  std::scanf("%d %d", &a, &d);

  if (a <= d)
    std::print("Yes");
  else
    std::print("No");

  return 0;
}
