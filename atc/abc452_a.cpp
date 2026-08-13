/*
 * https://atcoder.jp/contests/abc452/tasks/abc452_a
 */

#include <cstdio>
#include <print>

int h, w;

int main(void) {
  scanf("%d %d", &h, &w);

  if ((h >= 1 && h <= 9 && h & 1) &&
      ((h == 1 && w == 7) || (h > 1 && h == w))) {
    std::print("Yes");
  } else {
    std::print("No");
  }

  return 0;
}
