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
    ll n, c, d, h, dd, hh;
    cin >> n >> c;
    ll m = 0;
    for (auto i = 0; i < n; i++) {
      cin >> d >> h;
      if ((d - h) > m) {
        m = d - h;
        dd = d;
        hh = h;
      }
    }
    if (m == 0) {
      cout << -1 << "\n";
    } else {
      ll ans = 0;
      while (c > 0) {
        c -= dd;
        ans++;
        if (c > 0) c += hh;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}