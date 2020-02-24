#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  int a[n + 2];
  memset(a, 0, sizeof(a));
  for (register int i = 0; i < n; i++) cin >> a[i];
  string ans = "";
  int i = 0;
  while (i < n) {
    string s = "";
    if (a[i] == a[i + 1] - 1 and a[i] == a[i + 2] - 2) {
      int x = a[i];
      i = i + 2;
      while (i < n and (a[i] == a[i + 1] - 1)) i++;
      s = to_string(x) + "..." + to_string(a[i]);
    } else {
      s = to_string(a[i]);
    }
    if (i < n - 1) s += ',';
    ans += s;
    i++;
  }
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