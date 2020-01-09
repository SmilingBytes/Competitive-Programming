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
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll n, q;
    cin >> n >> q;
    ll b[n] = {0}, c[n] = {0};
    for (auto i = 1; i < n; i++) {
      ll tmp;
      cin >> tmp;
      if (i % 2 == 0) {
        b[i] = b[i - 1] - tmp;
        c[i] = c[i - 1] + tmp;
      } else {
        b[i] = b[i - 1] + tmp;
        c[i] = c[i - 1] - tmp;
      }
    }
    for (auto i = 0; i < q; i++) {
      ll x, y;
      cin >> x >> y;
      ll dif = abs(x - y);
      if (x == 1 or y == 1) {
        if (dif % 2 == 0) {
          cout << "UNKNOWN"
               << "\n";
        } else {
          int index = max(x, y);
          cout << b[index - 1] << "\n";
        }
      } else {
        if (dif % 2 == 0) {
          ll ans = 0;
          if (x % 2 == 0) {
            ans += b[x - 1];
            ans += c[y - 1];
          } else {
            ans += c[x - 1];
            ans += b[y - 1];
          }
          cout << ans << "\n";
        } else {
          cout << "UNKNOWN"
               << "\n";
        }
      }
    }
  }
  return 0;
}