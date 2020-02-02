/**
 *    author:  ismail
 *    created: 29.01.2020  21:17:13
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int tc;
  cin >> tc;
  while (tc--) {
    string s, t, z;
    cin >> s >> t;
    unordered_map<char, int> mp, used;
    vector<int> a[27];
    int sn = sz(s);
    char ch;
    for (int i = 0; i < sn; i++) {
      ch = s[i];
      a[ch - 'a'].push_back(i);
      mp[ch]++;
    }
    int n = sz(t), i = 0, pos = 0, npos = 0, ans = 0;
    bool f = true;
    while (i < n) {
      ch = t[i];
      if (mp[ch] == 0) {
        f = false;
        break;
      }
      used[ch]++;
      if (mp[ch] < used[ch]) {
        ans++;
        i--;
        pos = 0;
        used.clear();
      } else {
        vector<int> v = a[ch - 'a'];
        int j = v[used[ch] - 1];
        npos = v[j];
        while (npos <= pos) {
          j++;
          if (j < sz(v)) {
            npos = v[j];
          } else {
            break;
          }
        }
        if (j >= sz(v)) {
          ans++;
          i--;
          used.clear();
          pos = 0;
        } else {
          pos = v[j];
        }
      }
      i++;
    }

    cout << (f ? ans + 1 : -1) << "\n";
  }

  return 0;
}