/*
 * https://atcoder.jp/contests/abc467/tasks/abc465_c
 */

#include <array>
#include <cstdint>
#include <cstdio>

using u32 = std::uint32_t;

constexpr u32 LIMIT = 500000;

std::array<u32, LIMIT * 2> a{};

u32 n;
std::array<char, LIMIT + 1> s;

int main() {
  std::scanf("%d %s", &n, s.data());

  auto itb = a.begin() + n;
  auto itf = a.begin() + n + 1;
  bool d = false;

  for (u32 k = 1; k <= n; k++) {
    if (s[k - 1] == 'o') {
      d ^= true;
      *(d ? (itf++) : (itb--)) = k;
    } else {
      *(d ? (itb--) : (itf++)) = k;
    }
  }

  if (d) {
    for (auto i = itf - 1; i != itb; i--) {
      std::printf("%d ", *i);
    }
  } else {
    for (auto i = itb + 1; i != itf; i++) {
      std::printf("%d ", *i);
    }
  }

  return 0;
}
