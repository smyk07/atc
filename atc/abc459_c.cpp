/*
 * https://atcoder.jp/contests/abc467/tasks/abc459_c
 */

#include "ftree.hpp"
#include "io.hpp"
#include "svec.hpp"
#include "types.hpp"

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

constexpr u64 LIMIT = 300'000;

u32 n, q;
u32 qi, x, y;

u64 dec{0};
clix::svec<u64, LIMIT> cs{};
clix::ftree<LIMIT + 4> bit{cs};

u64 t{0};

i32 main() {
  std::tie(n, q) = io.read<u32, 2>();
  bit.update(0, n);

  for (u64 i = 0; i < q; i++) {
    io.read(&qi);

    if (qi == 1) {
      io.read(&x);
      x--;

      u64 old_c = cs[x];
      bit.update(old_c, -1);
      cs[x]++;
      bit.update(cs[x], +1);

      if (bit.range_query(dec, dec) == 0)
        dec++;
    } else {
      io.read(&y);

      t = y + dec;

      if (t > q) {
        io.write(0);
      } else {
        io.write(n - bit.query(t - 1));
      }

      io.newline();
    }
  }

  return 0;
}
