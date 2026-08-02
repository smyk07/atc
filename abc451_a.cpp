/*
 * https://atcoder.jp/contests/abc451/tasks/abc451_a
 */

#include <cstdio>
#include <cstring>
#include <print>

char s[10];

int main(void) {
  std::scanf("%s", s);

  if (std::strlen(s) % 5 == 0) {
    std::print("Yes");
  } else {
    std::print("No");
  }

  return 0;
}
