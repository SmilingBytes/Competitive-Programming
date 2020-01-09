#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
  int n, m;
  cin >> n >> m;
  ull a[n], sum[n];
  memset(sum, 0, sizeof(sum));
  for (auto &x : a) cin >> x;
  sort(a, a + n);
  ull ans = 0;
  for (register int i = 0; i < n; i++) {
    sum[i % m] += a[i];
    ans += sum[i % m];
    cout << ans << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  solve();
  return 0;
}