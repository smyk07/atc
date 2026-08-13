/*
 * https://atcoder.jp/contests/abc452/tasks/abc452_b
 */

#include <stdio.h>

int h, w;

int main(void) {
  scanf("%d %d", &h, &w);

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if ((i == 0 || i == h - 1) || (j == 0 || j == w - 1)) {
        printf("#");
      }

      else {
        printf(".");
      }
    }
    printf("\n");
  }

  return 0;
}
