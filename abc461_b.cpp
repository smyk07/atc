/*
 * https://atcoder.jp/contests/abc461/tasks/abc461_b
 */

#include <cstdio>
#include <print>

int n;

int axe, owner;

int map[101];

int main(void) {
  std::scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    std::scanf("%d", &axe);
    map[i] = axe;
  }

  for (int i = 1; i <= n; i++) {
    std::scanf("%d", &owner);

    if (map[owner] != i) {
      std::print("No");
      goto exit;
    }
  }

  std::print("Yes");

exit:
  return 0;
}
