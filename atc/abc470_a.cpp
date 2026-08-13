/*
 * https://atcoder.jp/contests/abc467/tasks/abc470_a
 */

#include <cstdint>
#include <cstdio>

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using u32 = std::uint32_t;

u32 n;

int main() {
  std::scanf("%d", &n);

  for (u32 i = 1; i <= n; i++) {
    if (i % 3 == 0) {
      std::printf("Fizz\n");
      continue;
    }

    std::printf("%d\n", i);
  }

  return 0;
}
