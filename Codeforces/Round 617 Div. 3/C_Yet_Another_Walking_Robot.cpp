/**
 *    author:  ismail
 *    created: 09.02.2020  15:29:48
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ff first
#define ss second
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

// uuldr 0 1 0 2 - 1 2 -
// 1 1 0 1

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<int, int>, int> mp;
    pair<int, int> ans, p;
    ans = p = make_pair(0, 0);
    int mn = 1e9;
    char ch;
    for (int i = 0; i < n; i++) {
      ch = s[i];
      if (ch == 'L')
        p.ff--;
      else if (ch == 'R')
        p.ff++;
      else if (ch == 'U')
        p.ss++;
      else if (ch == 'D')
        p.ss--;
      if (mp.find(p) != mp.end()) {
        if ((i + 1) - mp[p] < mn) {
          ans.ff = mp[p] + 1;
          ans.ss = i + 1;
          mn = (i + 1) - mp[p];
        }
      } else if (p.ff == 0 and p.ss == 0) {
        if ((i + 1) - 1 < mn) {
          ans.ff = 1;
          ans.ss = i + 1;
          mn = (i + 1) - mp[p];
        }
      }
      mp[p] = i + 1;
    }
    if (ans.ff == ans.ss)
      cout << -1 << "\n";
    else
      cout << ans.ff << " " << ans.ss << "\n";
  }
  return 0;
}