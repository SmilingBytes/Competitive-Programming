/**
 *    author:  ismail
 *    created: 12.02.2020  20:48:53
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  ll n, g, b;
  cin >> n >> g >> b;
  ll req = (n + 1) / 2;
  ll ans = 0LL, good = g, bad = b;
  if (req <= g) return cout << n << "\n", 0;

  while (req > 0 or good + bad < n) {
    if (req > g) {
      req -= g;
      good += g;
      bad += b;
    } else {
      if (good + bad + req < n) {
        // ll need = n - goo
      }
    }
  }

  // g b g b g
  return cout << ans << '\n', 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}