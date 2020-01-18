#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  ll n, m, ans = 1e9;
  cin >> n >> m;
  int a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    ll x = (b[0] + m - a[i]) % m;
    bool f = true;
    for (int j = 0; j < n; j++)
      if (b[j] != (a[(i + j) % n] + x) % m) f = false;
    if (f) ans = min(ans, x);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  solve();
  return 0;
}