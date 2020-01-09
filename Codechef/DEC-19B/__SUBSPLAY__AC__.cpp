#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n, ans = 1e9;
  string s;
  cin >> n >> s;
  int a[27];
  memset(a, -1, sizeof a);
  for (register int i = 0, d; i < n; i++) {
    d = s[i] - 'a';
    if (a[d] != -1) ans = min(ans, (i - a[d]));
    a[d] = i;
  }
  cout << (ans == 1e9 ? 0 : n - ans) << "\n";
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
  return 0;
}