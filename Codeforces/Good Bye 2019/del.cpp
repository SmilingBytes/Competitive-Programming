// https://codeforces.com/contest/1282/problem/B2
/**
 *    author:  ismail
 *    created: 29.12.2019  20:43:04
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  ll n, p, k;
  cin >> n >> p >> k;
  ll a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[0] = 0;
  sort(a, a + n + 1);
  ll ans = 0, sm = 0;
  for (int i = 0; i < k; i++) {
    sm += a[i];
    if (sm > p) break;
    ll cnt = 0;
    for (int j = i + k, np = p - sm; j <= n and a[j] <= np; j += k) {
      cnt++;
      np -= a[j];
    }
    ll newAns = i + (cnt * k);
    if (ans <= newAns) {
      ans = newAns;
    } else {
      break;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}