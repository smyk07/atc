/*
 * https://atcoder.jp/contests/abc458/tasks/abc458_b
 */

#include <iostream>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w;

  std::cin >> h >> w;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      std::cout << (4 - (i == 0) - (i == h - 1) - (j == 0) - (j == w - 1))
                << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
