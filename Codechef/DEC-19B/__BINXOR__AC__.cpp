#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

const ll mod = 1e9 + 7;
ll f[100001];

ll gcdExtended(ll a, ll b, ll *x, ll *y);

ll modInverse(ll b) {
  ll x, y;  // used in extended GCD algorithm
  ll g = gcdExtended(b, mod, &x, &y);
  if (g != 1) return -1;
  return (x % mod + mod) % mod;
}

ll modDivide(ll a, ll b) {
  a = a % mod;
  ll inv = modInverse(b);
  ll res = (inv * a) % mod;
  return res;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  ll x1, y1;
  ll gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}

void fact() {
  f[0] = 1;
  f[1] = 1;
  for (ll i = 2; i <= 100000; i++) f[i] = (f[i - 1] * i) % mod;
}

void solve() {
  ll n;
  string a, b;
  cin >> n >> a >> b;
  ll na1 = count(all(a), '1');
  ll nb1 = count(all(b), '1');
  ll mx1 = na1 + nb1;
  if (mx1 > n) {
    ll tmp = mx1 - n;
    mx1 = n - tmp;
  }
  ll mn1 = max(na1, nb1) - min(na1, nb1);
  ll ans = 0, tmp = 0;
  for (ll i = mx1; i >= mn1; i -= 2) {
    ll bb = f[i] * f[n - i];
    tmp = modDivide(f[n], bb);
    ans = (ans + tmp) % mod;
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  fact();
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
