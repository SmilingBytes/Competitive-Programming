#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  string s, h, S;
  cin >> s >> h;
  int n = sz(s), nn = sz(h);
  if (n > nn) return cout << "NO\n", 0;
  sort(all(s));
  for (register int i = 0; i <= nn - n; i++) {
    S = h.substr(i, n);
    sort(all(S));
    if (s == S) return cout << "YES\n", 0;
  }
  return cout << "NO\n", 0;
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