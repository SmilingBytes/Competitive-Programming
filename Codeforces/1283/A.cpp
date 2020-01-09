// https://codeforces.com/contest/1283/problem/0
/**
 *    author:  ismail
 *    created: 28.12.2019  23:06:56
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int h, m;
  cin >> h >> m;
  h = 24 - h - 1;
  m = 60 - m;
  int ans = m + (h * 60);
  cout << ans << '\n';
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