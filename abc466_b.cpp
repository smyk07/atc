/*
 * https://atcoder.jp/contests/abc467/tasks/abc466_b
 */

#include <array>
#include <cstdio>

using i64 = long long;

i64 n, m;
i64 color, size;

// idx = color
// val = size
std::array<i64, 100> bs{};

int main() {
  std::scanf("%lld %lld", &n, &m);

  while (n-- > 0) {
    std::scanf("%lld", &color);
    std::scanf("%lld", &size);
    color--;

    if (size > bs[color])
      bs[color] = size;
  }

  for (i64 i = 0; i < m; i++) {
    size = bs[i];

    if (size > 0)
      std::printf("%lld ", size);
    else
      std::printf("-1 ");
  }

  return 0;
}
