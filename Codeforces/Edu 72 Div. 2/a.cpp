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
    ll s, i, e;
    cin >> s >> i >> e;
    ll m = s + e - i;
    if (m <= 0)
      cout << 0 << "\n";
    else if (e == 0) {
      cout << 1 << "\n";
    } else {
      ll ans = m / 2 + m % 2;
      ans = min(ans, e + 1);
      cout << ans << "\n";
    }
  }
  return 0;
}