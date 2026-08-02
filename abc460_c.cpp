/*
 * https://atcoder.jp/contests/abc460/tasks/abc460_c
 */

#pragma GCC optimize("Ofast")

#include <algorithm>
#include <cstdio>
#include <print>
#include <vector>

int n, m;

std::vector<int> shari;
std::vector<int> neta;

int sushi = 0;

int main(void) {
  std::scanf("%d %d", &n, &m);
  shari.resize(n);
  neta.resize(m);

  for (int i = 0; i < n; i++) {
    std::scanf("%d", &shari[i]);
  }

  for (int i = 0; i < m; i++) {
    std::scanf("%d", &neta[i]);
  }

  std::sort(shari.begin(), shari.end());
  std::sort(neta.begin(), neta.end());

  auto si = shari.begin();
  auto ni = neta.begin();

  while (si != shari.end() && ni != neta.end()) {
    if (*ni <= 2 * *si) {
      sushi++;
      si++;
      ni++;
      continue;
    }

    si++;
  }

  std::print("{}", sushi);

  return 0;
}
