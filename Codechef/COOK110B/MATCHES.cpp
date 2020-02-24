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
  freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  ll matches[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll m = n + k;
    ll ans = 0;
    while (m > 0) {
      ll d = m % 10;
      ans += matches[d];
      m /= 10;
    }
    cout << n << " " << k << " => " << ans << "\n";
  }
  return 0;
}