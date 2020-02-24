#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  s = "ss" + s + "ss";
  vector<int> a;
  for (register int i = 2; i < n + 2; i++) {
    if (s[i] == 'o') {
      if (s[i - 2] == 't' and s[i - 1] == 'w' and s[i + 1] == 'n' and
          s[i + 2] == 'e') {
        a.push_back(i - 1);
      } else if (s[i - 2] == 't' and s[i - 1] == 'w') {
        a.push_back(i - 2);
      } else if (s[i + 1] == 'n' and s[i + 2] == 'e') {
        a.push_back(i);
      }
    }
  }
  cout << sz(a) << "\n";
  if (sz(a) > 0)
    for (const auto val : a) cout << val << " ";
  cout << "\n";
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