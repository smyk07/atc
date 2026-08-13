/*
 * https://atcoder.jp/contests/abc461/tasks/abc461_c
 */

#include <cstdio>
#include <print>
#include <queue>
#include <utility>
#include <vector>

typedef long long ll;

int n, k, m;
int v, c;

std::priority_queue<std::pair<int, int>> gems;
std::vector<std::pair<int, int>> skipped;
bool colors[200001];

int ccount = 0;
ll sum = 0;

int main(void) {
  std::scanf("%d %d %d", &n, &k, &m);

  for (int i = 0; i < n; i++) {
    std::scanf("%d %d", &c, &v);
    gems.push(std::make_pair(v, c));
  }

  while (ccount < m && !gems.empty()) {
    auto g = gems.top();
    gems.pop();

    if (!colors[g.second]) {
      colors[g.second] = true;
      sum += g.first;
      ccount++;
      k--;
    } else {
      skipped.push_back(g);
    }
  }

  for (auto sg : skipped) {
    gems.push(sg);
  }

  while (k > 0 && !gems.empty()) {
    auto g = gems.top();
    gems.pop();
    sum += g.first;
    k--;
  }

  std::print("{}", sum);

  return 0;
}
