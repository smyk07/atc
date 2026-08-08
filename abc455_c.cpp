/*
 * https://atcoder.jp/contests/abc456/tasks/abc455_c
 */

#include <array>
#include <cstdint>
#include <cstdio>
#include <numeric>
#include <unordered_map>

using u32 = std::uint32_t;

u32 n, k, a;

std::unordered_map<u32, u32> map;

std::array<u32, 300000> w;
u32 track{0};

u32 res{0};

int main(void) {
  std::scanf("%d %d", &n, &k);

  while (n-- > 0) {
    std::scanf("%d", &a);
    map[a]++;
  }

  for (auto [k, v] : map) {
    w[track++] = k * v;
  }

  auto eit = w.begin() + track;
  auto e = eit - k;

  if (e >= w.begin())
    res = std::reduce(w.begin(), e);

  std::printf("%d", res);

  return 0;
}
