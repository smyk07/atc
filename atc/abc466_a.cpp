/*
 * https://atcoder.jp/contests/abc467/tasks/abc466_a
 */

#include <cstdio>

using i64 = long long;

i64 n;
i64 h;

int main() {
  std::scanf("%lld", &n);

  while (n-- > 0) {
    std::scanf("%lld", &h);
    if (h >= 0) {
      std::printf("No");
      return 0;
    }
  }

  std::printf("Yes");

  return 0;
}
