#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int a, b;
  cin >> a >> b;
  if (a == b) return cout << 0 << endl, 0;
  int dif = abs(a - b);
  int ans = dif / 5;
  int rem = dif % 5;
  if (rem == 0) return cout << ans << endl, 0;
  cout << ((rem == 3 or rem == 4) ? ans + 2 : ans + 1) << endl;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}