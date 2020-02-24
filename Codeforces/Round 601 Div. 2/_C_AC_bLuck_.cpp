#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
const auto start_time = chrono::steady_clock::now();

void solve() {
  int n, cnt0 = 0, cnt00 = 0, cnt1 = 0, cnt2 = 0;
  cin >> n;
  unordered_map<int, int> mp[n + 1];
  int ans[n];
  for (register int i = 1, a, b, c; i <= n - 2; i++) {
    cin >> a >> b >> c;
    mp[a][b]++;
    mp[a][c]++;
    mp[b][a]++;
    mp[b][c]++;
    mp[c][a]++;
    mp[c][b]++;
  }

  for (register int i = 1; i <= n; i++) {
    int cnt = 0;
    for (const auto x : mp[i])
      if (x.ss > 1) cnt++;
    if (cnt == 0) (cnt0 == 0) ? cnt0 = i : cnt00 = i;
    if (cnt == 1) (cnt1 == 0) ? cnt1 = i : cnt2 = i;
  }

  ans[0] = cnt0;
  for (const auto x : mp[ans[0]])
    if (x.ff == cnt1 or x.ff == cnt2) ans[1] = x.ff;

  for (const auto x : mp[ans[1]])
    if (x.ss == 2) ans[2] = x.ff;

  for (register int i = 3; i < n - 1; i++) {
    int prev = ans[i - 1];
    for (const auto x : mp[prev])
      if (x.ss == 2 and x.ff != ans[i - 2]) ans[i] = x.ff;
  }

  ans[n - 1] = cnt00;
  for (const auto val : ans) cout << val << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  solve();
  const auto _now = chrono::steady_clock::now();
  cerr << "\nTime elapsed: "
       << chrono::duration_cast<chrono::milliseconds>(_now - start_time).count()
       << " ms\n";
  return 0;
}