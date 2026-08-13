/*
 * https://atcoder.jp/contests/abc467/tasks/abc466_c
 */

#include <algorithm>
#include <array>
#include <cstdio>

using i64 = long long;

i64 n;

std::array<char, 4> s = {'g', 'a', 'y', '\0'};

[[gnu::always_inline]]
inline bool ask(i64 a, i64 b) {
  std::printf("? %lld %lld\n", a, b);
  std::fflush(stdout);

  std::scanf("%3s", s.data());
  if (s[0] == 'Y')
    return true;
  else
    return false;
}

[[gnu::always_inline]]
inline void answer(i64 ans) {
  std::printf("! %lld\n", ans);
  std::fflush(stdout);
}

i64 m{1};

i64 res{};

int main() {
  std::scanf("%lld", &n);

  for (i64 i = 1; i <= n; i++) {
    m = std::max(i, m);

    while (m < n) {
      if (ask(i, m + 1))
        m++;
      else
        break;
    }

    res += m - i;
  }

  answer(res);

  return 0;
}
