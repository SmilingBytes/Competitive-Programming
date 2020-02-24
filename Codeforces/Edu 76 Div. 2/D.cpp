#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
void solve() {
  int n, m, i, a, b;
  cin >> n;
  vector<int> p(n);
  for (int &x : p) cin >> x;
  cin >> m;
  vector<int> e(n + 1, 0);
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    e[b] = max(e[b], a);
  }
  for (i = n; i > 0; i--) e[i - 1] = max(e[i - 1], e[i]);
  int ans = 1, l = 0, cmax = 0;
  b = 0;
  for (i = 0; i < n; i++) {
    cmax = max(cmax, p[i]);
    if (e[i - l + 1] >= cmax) b = i + 1;
    if (e[1] < p[i]) {
      cout << "-1\n";
      return;
    }
    if (b == i) {
      ans++;
      l = i;
      i--;
      cmax = 0;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}