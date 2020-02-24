#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  for (int tc = 0; tc < t; ++tc) {
    string a;
    cin >> a;
    string s[2];
    for (auto x : a) s[int(x - '0') & 1] += x;

    reverse(s[0].begin(), s[0].end());
    reverse(s[1].begin(), s[1].end());

    string res = "";
    while (!(s[0].empty() && s[1].empty())) {
      if (s[0].empty()) {
        res += s[1].back();
        s[1].pop_back();
        continue;
      }
      if (s[1].empty()) {
        res += s[0].back();
        s[0].pop_back();
        continue;
      }

      if (s[0].back() < s[1].back()) {
        res += s[0].back();
        s[0].pop_back();
      } else {
        res += s[1].back();
        s[1].pop_back();
      }
    }

    cout << res << endl;
  }
  return 0;
}