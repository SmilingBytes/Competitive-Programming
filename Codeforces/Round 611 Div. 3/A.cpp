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
  cout << 60 - m + (23 - h) * 60 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}