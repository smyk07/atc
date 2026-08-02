/*
 * https://atcoder.jp/contests/abc458/tasks/abc458_d
 */

#pragma GCC optimize("O3")

#include <cstdio>
#include <queue>
#include <vector>

typedef long long ll;

ll x;
ll q;
ll a, b;
ll temp;

typedef std::priority_queue<ll, std::vector<ll>, std::greater<ll>> min_queue;

typedef std::priority_queue<ll, std::vector<ll>, std::less<ll>> max_queue;

ll pushq(min_queue &minq, max_queue &maxq, const ll num) {
  if ((maxq.empty() && minq.empty()) || num > maxq.top()) {
    minq.push(num);
  } else {
    maxq.push(num);
  }

  if (maxq.size() > (minq.size() + 1)) {
    temp = maxq.top();
    maxq.pop();
    minq.push(temp);
  } else if (minq.size() > maxq.size()) {
    temp = minq.top();
    minq.pop();
    maxq.push(temp);
  }

  if (minq.size() == maxq.size()) {
    return ((minq.top()) + (maxq.top())) / 2;
  } else {
    return maxq.top();
  }
}

int main(void) {
  max_queue maxq;
  min_queue minq;

  scanf("%lld", &x);
  pushq(minq, maxq, x);
  scanf("%lld", &q);

  for (; q > 0; q--) {
    scanf("%lld %lld", &a, &b);

    pushq(minq, maxq, a);
    ll med = pushq(minq, maxq, b);

    printf("%lld\n", med);
  }

  return 0;
}
