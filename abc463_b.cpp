/*
 * https://atcoder.jp/contests/abc467/tasks/abc463_b
 */

#include <array>
#include <cstdio>

using i64 = long long;

i64 n;
char x;

std::array<char, 6> s = {'d', 'i', 'h', 'h', 'h', '\0'};

int main() {
  std::scanf("%lld %c", &n, &x);
  x %= 65;

  while (n-- > 0) {
    std::scanf("%5s", s.data());
    if (s[x] == 'o') {
      std::printf("Yes");
      return 0;
    }
  }

  std::printf("No");

  return 0;
}
