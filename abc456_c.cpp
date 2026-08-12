/*
 * https://atcoder.jp/contests/abc467/tasks/abc456_c
 */

#include "io.hpp"
#include "svec.hpp"
#include "types.hpp"

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

constexpr u64 LIMIT{300000 + 5};
constexpr u64 MODCON{998244353};

clix::svec<char, LIMIT> s{};

u64 len{0};

u64 res{0};

int main() {
  io.read(s, LIMIT);

  for (u64 i = 0; s[i] != '\0'; i++) {
    if (i == 0 || s[i] != s[i - 1])
      len++;
    else
      len = 1;

    res = (res + len) % MODCON;
  }

  io.write(res);

  return 0;
}
