#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
const int mod = 1e9 + 7;

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll n, c, d, h, dd, mxd = 0, md = 0;
    cin >> n >> c;
    for (auto i = 0; i < n; i++) {
      cin >> d >> h;
      mxd = max(mxd, d);
      if ((d - h) > md) {
        md = d - h;
        dd = d;
      }
    }
    if (mxd >= c) {
      cout << 1 << "\n";
    } else if (md == 0) {
      cout << -1 << "\n";
    } else {
      ll ans = 1;
      c = c - mxd;
      ans += c / md;
      if (c % md != 0) ans += 1;
      cout << ans << "\n";
    }
  }
  return 0;
}