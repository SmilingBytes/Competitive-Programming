// https://codeforces.com/contest/1279/problem/0
/**
 *    author:  Smile.Forever
 *    created: 27.12.2019  20:41:05
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  ll r, g, b;
  cin >> r >> g >> b;
  ll mx = max(r, max(g, b));
  ll n = r + g + b - mx;
  cout << ((n + 1 >= mx) ? "Yes\n" : "No\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("correct.txt", "w", stdout);
#endif
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}