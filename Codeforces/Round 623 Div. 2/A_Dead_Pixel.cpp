/**
 *    author:  ismail
 *    created: 24.02.2020  19:52:51
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  ll a, b, x, y;
  cin >> a >> b >> x >> y;
  int dx, dy;
  dx = max(x, a - (x + 1));
  dy = max(y, b - (y + 1));
  ll ans = max(dx * b, dy * a);
  cout << ans << '\n';
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}