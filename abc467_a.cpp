/*
 * https://atcoder.jp/contests/abc467/tasks/abc467_a
 */

#include <cstdio>

using i64 = long long;

i64 h, w, bmi;

int main() {
  std::scanf("%lld %lld", &h, &w);

  if (400 * w >= h * h)
    std::printf("Yes\n");
  else
    std::printf("No\n");

  return 0;
}
