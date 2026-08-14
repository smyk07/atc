/*
 * https://cses.fi/problemset/task/1069
 */

#include "io.hpp"
#include "svec.hpp"
#include "types.hpp"

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

constexpr u64 LIMIT = 1'000'000;

clix::svec<char, LIMIT> s;

u64 cl{1}, ml{1};

i32 main() {
  io.read(s, LIMIT);

  const auto sv = s.get_sv();

  for (u64 i = 1; i < sv.size(); i++) {
    if (sv[i] == sv[i - 1])
      cl++;

    else
      ml = std::max(ml, cl), cl = 1;
  }

  ml = std::max(ml, cl);

  io.write(ml);

  return 0;
}
