/*
 * https://cses.fi/problemset/task/1068/
 */

#include "io.hpp"
#include "types.hpp"

constexpr u64 LIMIT = 1'000'000;

u64 n;

i32 main() {
  io.read(&n);

  io.write(n);
  io.space();

  while (n != 1) {
    if (n % 2 == 0)
      n /= 2;
    else
      n = (n * 3) + 1;

    io.write(n);
    io.space();
  }

  return 0;
}
