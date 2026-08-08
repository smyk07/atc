/*
 * https://atcoder.jp/contests/abc467/tasks/abc469_c
 */

#include <array>
#include <cstdint>
#include <cstdio>

using u32 = std::uint32_t;

#define LIMIT 800000

u32 n;

std::array<char, LIMIT + 1> s;
u32 tx{0};
std::array<u32, LIMIT + 1> map;

int main() {
  std::scanf("%d %s", &n, s.data());

  for (u32 i = 0; i < n; i++) {
    if (s[i] == 'x')
      map[tx] = i + 1, tx++;
  }

  for (u32 k = 1; k <= n; k++) {
    if (k <= tx) {
      std::printf("%d\n", map[k - 1]);
    } else {
      std::printf("%d\n", n);
    }
  }

  return 0;
}
