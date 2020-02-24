#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n;
  cin >> n;
  if (n <= 9) return cout << n << "\n", 0;
  int dgt = 0, m = n;
  while (m > 0) {
    m /= 10;
    dgt++;
  }
  int ans = (dgt - 1) * 9;
  int mn = 1;
  for (register int i = 1; i < dgt; i++) mn = (mn * 10) + 1;
  int x = mn;
  while (n >= x) {
    x += mn;
    ans++;
  }
  return cout << ans << "\n", 0;
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
  return 0;
}