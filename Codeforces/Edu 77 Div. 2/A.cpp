#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
const auto start_time = chrono::steady_clock::now();
#define w(a) std::cerr << #a << " : " << (a) << "\n";

const ll mod = 1000000007;
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}

bool solve() {
  ll c, k;
  cin >> c >> k;
  if (k == 1) return cout << 1 << "\n", 0;
  if (c == 1) return cout << powmod(k, 2) << "\n", 0;
  if (k <= c) return cout << k << "\n", 0;
  ll div = k / c;
  ll rem = k % c;
  ll dif = c - rem;
  ll ans = (powmod(div, 2)) * dif;
  ans += (powmod(div + 1, 2)) * rem;
  cout << ans << '\n';
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  register int tc;
  cin >> tc;
  while (tc--) solve();

  const auto _now = chrono::steady_clock::now();
  cerr << "\nTime elapsed: "
       << chrono::duration_cast<chrono::milliseconds>(_now - start_time).count()
       << " ms\n";
  return 0;
}