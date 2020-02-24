#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  int a[11];
  memset(a, 0, sizeof(a));
  for (register int i = 0, p, s; i < n; i++) {
    cin >> p >> s;
    a[p] = max(a[p], s);
  }
  int ans = 0;
  for (register int i = 1; i <= 8; i++) ans += a[i];
  cout << ans << '\n';
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