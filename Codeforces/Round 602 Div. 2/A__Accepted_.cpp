#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n, x, a = 1, b = 1e9;
  cin >> n;

  for (register int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    a = max(x, a);
    b = min(y, b);
  }
  int ans = a - b;
  ans = max(0, ans);
  return cout << (n == 1 ? 0 : ans) << '\n', 0;
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