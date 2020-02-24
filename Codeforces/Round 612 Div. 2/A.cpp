// https://codeforces.com/contest/1287/problem/A
/**
 *    author:  ismail
 *    created: 05.01.2020  20:10:49
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  string s;
  cin >> n >> s;
  bool f = false;
  int mx = 0, cnt = 0;
  for (char ch : s) {
    if (f) {
      if (ch == 'A') {
        mx = max(mx, cnt);
        cnt = 0;
      } else {
        cnt++;
      }
    } else {
      if (ch == 'A') f = true;
    }
  }
  mx = max(mx, cnt);

  cout << mx << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}