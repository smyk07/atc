/*
 * https://atcoder.jp/contests/abc467/tasks/abc470_b
 */

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using u32 = std::uint32_t;

constexpr u32 LIMIT = 100;

u32 n;
u32 c;
std::array<u32, LIMIT + 1> cs;

u32 res{0};

int main() {
  std::scanf("%d", &n);

  for (u32 i = 0; i < n; i++) {
    std::scanf("%d", &c);
    cs[c]++;
  }

  auto max = *std::max_element(cs.begin(), cs.end());

  for (auto c : cs) {
    res += c;
  }

  res -= max;

  std::printf("%d", res);

  return 0;
}
