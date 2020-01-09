#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  string s, h;
  cin >> s >> h;
  int n = sz(s), nn = sz(h), cnt = 0;
  if (n > nn) return cout << "NO\n", 0;
  unordered_map<char, int> mp, chk;
  for (auto ch : s) mp[ch]++;
  int m = sz(mp);

  char ch;
  for (register int i = 0; i < n; i++) {
    ch = h[i];
    if (mp[ch]) {
      if (mp[ch] == chk[ch]) {
        cnt--;
      }
      chk[ch]++;
      if (mp[ch] == chk[ch]) {
        cnt++;
      }
    }
  }
  if (cnt == m) {
    return cout << "YES\n", 0;
  }

  for (register int i = n; i < nn; i++) {
    ch = h[i];
    char c = h[i - n];
    if (mp[c]) {
      if (mp[c] == chk[c]) {
        cnt--;
      }
      if (mp[c] + 1 == chk[c]) {
        cnt++;
      }
      chk[c]--;
    }
    if (mp[ch]) {
      if (mp[ch] == chk[ch]) {
        cnt--;
      }
      chk[ch]++;
      if (mp[ch] == chk[ch]) {
        cnt++;
      }
    }
    if (cnt == m) {
      return cout << "YES\n", 0;
    }
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