/**
 *    author:  ismail
 *    created: 17.06.2020  12:13:38
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n, k, ans = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  if (n == 1) return cout << (s[0] == '0' ? 1 : 0) << "\n", 0;
  if (n == k) {
    int i = 0;
    while (i < n and s[i] == '0') i++;
    return cout << (i == n ? 1 : 0) << "\n", 0;
  }
  vector<bool> nxt(n, 0);
  int d = k;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      if (d >= k)
        nxt[i] = 1;
      else
        d++;
    } else
      d = 0;
  }
  int i = 0;
  d = k;
  while (i < n) {
    if (s[i] == '0' and d >= k) {
      if (nxt[i]) ans++, i += k;
    } else if (s[i] == '0')
      d++;
    else
      d = 0;

    i++;
  }

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