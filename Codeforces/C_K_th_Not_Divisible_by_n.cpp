/**
 *    author:  ismail
 *    created: 09.05.2020  21:56:48
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n, k, ans;
  cin >> n >> k;
  int d = n - 1;
  int r = k / d;
  if (k % d == 0) {
    ans = r * n - 1;
  } else {
    int m = n * r;
    int inc = k - (m - r);
    ans = m + inc;
  }
  cout << ans << '\n';
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
