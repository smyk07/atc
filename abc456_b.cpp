/*
 * https://atcoder.jp/contests/abc456/tasks/abc456_b
 */

#include <cstdio>

int face;

int faces[3][7] = {};
/*
 * 4s 5s 6s
 * 4s 5s 6s
 * 4s 5s 6s
 */

long double wp;

int main(void) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      scanf("%d", &face);

      if (face == 4)
        faces[i][4]++;
      else if (face == 5)
        faces[i][5]++;
      else if (face == 6)
        faces[i][6]++;
    }
  }

  wp = ((faces[0][4] * faces[1][5] * faces[2][6]) +
        (faces[0][4] * faces[1][6] * faces[2][5]) +
        (faces[0][5] * faces[1][4] * faces[2][6]) +
        (faces[0][5] * faces[1][6] * faces[2][4]) +
        (faces[0][6] * faces[1][4] * faces[2][5]) +
        (faces[0][6] * faces[1][5] * faces[2][4])) /
       216.0;

  printf("%Lf", wp);

  return 0;
}
