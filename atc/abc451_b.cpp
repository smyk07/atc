/*
 * https://atcoder.jp/contests/abc451/tasks/abc451_b
 */

#include <stdio.h>

int n, h;
int a, b;

int pdept[101];
int fdept[101];

int main(void) {
  scanf("%d %d", &n, &h);

  for (; n > 0; n--) {
    scanf("%d %d", &a, &b);
    pdept[a]++;
    fdept[b]++;
  }

  for (int i = 1; i <= h; i++) {
    printf("%d\n", fdept[i] - pdept[i]);
  }

  return 0;
}
