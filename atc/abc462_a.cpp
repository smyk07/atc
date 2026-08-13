/*
 * https://atcoder.jp/contests/abc461/tasks/abc461_a
 */

#include <array>
#include <cctype>
#include <cstdio>
#include <string_view>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

std::array<char, 51> s{};

int main(void) {
  std::fill_n(s.begin(), 50, 's');
  s[50] = '\0';

  std::scanf("%s", s.data());

  const std::string_view sv(s.data());

  for (auto c : sv) {
    if (std::isdigit(static_cast<unsigned char>(c))) {
      std::printf("%c", c);
    }
  }

  return 0;
}
