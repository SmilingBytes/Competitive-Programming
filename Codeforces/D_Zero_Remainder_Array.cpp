/**
 *    author:  ismail
 *    created: 29.06.2020  01:19:56
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  ll n, k, ans = 0ll, d;
  cin >> n >> k;

  map<ll, ll> mp;
  while (n--) {
    cin >> d;
    d = k - d % k;
    if (d == k) continue;
    ans = max(ans, k * mp[d] + d + 1);
    mp[d]++;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}