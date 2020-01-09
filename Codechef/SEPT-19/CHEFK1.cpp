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
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    ll n, k, ans;
    cin >> n >> k;
    if (n - 1 > k) {
      cout << -1 << "\n";
    } else if (n == 1) {
      ans = (k == 0 or k == 1) ? k : -1;
      cout << ans << "\n";
    } else {
      if (k <= n + 1)
        ans = 2;
      else {
        // test
      }
    }
  }
  return 0;
}