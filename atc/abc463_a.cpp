/*
 * https://atcoder.jp/contests/abc467/tasks/abc463_a
 */

#include <cstdio>

using i64 = long long;

i64 x, y;

int main() {
  std::scanf("%lld %lld", &x, &y);

  if (y << 4 == (x << 3) + x)
    std::printf("Yes");
  else
    std::printf("No");

  return 0;
}
