/*
 * https://atcoder.jp/contests/abc453/tasks/abc453_b
 */

#include <cmath>
#include <cstdio>
#include <print>

int n, x;
int r;

int saved = 0;

int main(void) {
  scanf("%d %d", &n, &x);

  scanf("%d", &r);
  saved = r;
  std::println("0 {}", saved);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &r);
    if (std::abs(r - saved) >= x) {
      saved = r;
      std::println("{} {}", i, saved);
    }
  }

  return 0;
}
