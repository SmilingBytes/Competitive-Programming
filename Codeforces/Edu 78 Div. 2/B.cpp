#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

ll v[1000];

bool solve() {
  int a, b;
  cin >> a >> b;
  a = abs(a - b);
  if (a == 0) return cout << "0\n", 0;
  for (ll i = 1;; i++) {
    ll sm = i * (i + 1) / 2;
    if (a % 2 != sm % 2) continue;
    if (a > sm) continue;
    return cout << i << "\n", 0;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  v[0] = 0;
  for (register int i = 1; i < 1001; i++) v[i] = v[i - 1] + i;

  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}