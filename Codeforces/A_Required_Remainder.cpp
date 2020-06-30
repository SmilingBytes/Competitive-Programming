/**
 *    author:  ismail
 *    created: 28.06.2020  20:36:50
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int x, y, n;
  cin >> x >> y >> n;
  int ans = (n / x) * x + y;
  cout << (ans > n ? ans - x : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}