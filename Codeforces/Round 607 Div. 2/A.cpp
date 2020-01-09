#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  string s;
  cin >> s;
  int n = sz(s) - 1;
  if (s[n] == 'o' and s[n - 1] == 'p') return cout << "FILIPINO\n", 0;
  if (s[n] == 'u' and s[n - 1] == 's' and
          ((s[n - 2] == 'e' and s[n - 3] == 'd')) or
      ((s[n - 3] == 'm' and s[n - 2] == 'a')))
    return cout << "JAPANESE\n", 0;
  return cout << "KOREAN\n", 0;
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