#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  string s = "z", ss;
  cin >> ss;
  s += ss;
  s += "z";
  int n = sz(ss);
  if (n == 1) return cout << ((ss[0] == '?') ? "a" : ss) << "\n", 0;

  for (register int i = 1; i <= n; i++) {
    if (s[i] == '?') {
      for (char ch = 'a'; ch <= 'c'; ch++)
        if (s[i - 1] != ch and s[i + 1] != ch) {
          s[i] = ch;
          break;
        }
    } else if (s[i] == s[i - 1] or s[i] == s[i + 1]) {
      return cout << "-1\n", 0;
    }
  }
  for (register int i = 1; i <= n; i++) cout << s[i];
  return cout << "\n", 0;
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