/*
 * https://atcoder.jp/contests/abc457/tasks/abc457_c
 */

#include <stdio.h>
#include <vector>

typedef long long ll;

ll n, k;
ll l;
ll a;
ll c;

std::vector<std::vector<ll>> vec;
std::vector<ll> subvec;

ll block_size;

ll res;

int main(void) {
  scanf("%lld %lld", &n, &k);

  for (ll i = 0; i < n; i++) {
    scanf("%lld", &l);
    for (; l > 0; l--) {
      scanf("%lld", &a);
      subvec.push_back(a);
    }

    vec.push_back(subvec);
    subvec.clear();
  }

  for (ll i = 0; i < n; i++) {
    scanf("%lld", &c);

    block_size = vec[i].size() * c;

    if (k <= block_size) {
      res = vec[i][(k - 1) % (vec[i].size())];
      break;
    } else {
      k -= block_size;
    }
  }

  printf("%lld", res);

  return 0;
}
