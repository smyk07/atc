/*
 * https://cses.fi/problemset/task/1083
 */

#include "io.hpp"
#include "svec.hpp"
#include "types.hpp"

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

constexpr u64 LIMIT = 200'000;

u64 n;
clix::svec<u32, LIMIT> as;

u64 res{0};

i32 main() {
  io.read(&n);

  for (u64 i = 0; i < n; i++) {
    as.push_back(io.read<u32>());
  }

  for (u64 i = 1; i <= n; i++)
    res ^= i;

  for (auto a : as)
    res ^= a;

  io.write(res);

  return 0;
}
