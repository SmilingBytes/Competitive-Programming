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
#define ncr(n, r) (f[n] / (f[n - r] * f[r])) % mod
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  ll n, k;
  cin >> n >> k;
  ll a[n + 1], f[n + 1], cd = 0;
  f[0] = 1;
  a[0] = 1;
  for (auto i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i - 1] == a[i]) cd++;
    f[i] = (f[i - 1] * i) % mod;
  }

  ll ans = 1 + n, tmp = ncr(n, 2);

  if (k == 1)
    cout << ans << "\n";
  else if (k == 2)
    cout << (ans + tmp - cd) % mod << "\n";
  else if (cd == 0) {
    for (auto j = 2; j <= k; j++) {
      ans = (ans + (ncr(n, j))) % mod;
    }
    cout << ans << "\n";

  } else {
    ans += tmp - cd;
    for (auto i = 3; i <= k; i++) {
      ll nn = n - 2, r = i - 2, ignr = 0;
      ans = (ans + (ncr(n, i))) % mod;
      ans -= (cd * (ncr(n - 2, r))) % mod;
      for (auto j = 2; j <= cd and 2 * j <= i; j++) {
        ignr = (ignr + ((ncr(cd, j)) * (ncr((n - 2 * j), (i - 2 * j)))) % mod) %
               mod;
      }
      ans = (ans + ignr) % mod;
    }
    cout << ans << "\n";
  }
  return 0;
}