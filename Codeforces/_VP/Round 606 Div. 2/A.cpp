#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n;
  cin >> n;
  if (n < 10) return cout << n << "\n", 0;
  int dgt = ceil(log10(fabs(n) + 1));
  int ans = (dgt - 1) * 9;
  int mn = 1;
  for (register int i = 1; i < dgt; i++) mn = (mn * 10) + 1;
  int num = mn;
  int cnt = 0;
  while (n >= num) {
    cnt++;
    num += mn;
  }
  ans += cnt;
  cout << ans << '\n';
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