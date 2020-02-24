/**
 *    author:  ismail
 *    created: 12.02.2020  20:36:05
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  string s;
  cin >> s;
  int n = s.size(), ans = 0, cnt = 0;
  bool f = false, chk = false;
  for (int i = 0; i < n; i++) {
    if (f) {
      if (s[i] == '0') {
        ans++;
        cnt++;
        chk = true;
      } else {
        cnt = 0;
        chk = false;
      }
    } else {
      if (s[i] == '1') f = true;
    }
  }
  if (chk) ans -= cnt;
  cout << ans << '\n';
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}