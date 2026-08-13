/*
 * https://atcoder.jp/contests/abc467/tasks/abc445_c
 */

#include "io.hpp"
#include "svec.hpp"
#include "types.hpp"

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
  constexpr u64 LIMIT = 500000;

  auto n = io.read<u64>();
  clix::svec<u32, LIMIT> as;
  clix::svec<u32, LIMIT> res;

  io.read(as, n);

  for (u32 i = n; i >= 1; i--) {
    if (as[i - 1] == i)
      res[i - 1] = i;

    if (as[i - 1] > i)
      res[i - 1] = res[as[i - 1] - 1];
  }

  for (u32 i = 0; i < n; i++) {
    io.write(res[i]);
    io.space();
  }

  return 0;
}
