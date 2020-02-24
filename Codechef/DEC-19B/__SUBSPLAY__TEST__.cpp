#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n - 1);

  for (register int i = 0, u, v, e; i < n - 1; i++) cin >> u >> v >> b[i];
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  auto it = b.rbegin();
  auto iter = lower_bound(a.begin(), a.end(), *it);
  int ans = 0;
  if (a.end() - iter < 2) {
    ans += 2 + iter - a.end();
  } else {
    iter = a.end() - 2;
  }
  iter--;
  it++;

  for (; it != b.rend(); it++) {
    if (*it > *iter) {
      ans += 1;
    } else {
      iter--;
    }
  }
  cout << ans << "\n";
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