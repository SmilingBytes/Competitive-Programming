/**
 *    author:  ismail
 *    created: 31.05.2020  19:27:56
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int d = n / k;
  if (m == 0) return cout << "0\n", 0;
  if (m <= d) return cout << m << "\n", 0;
  int n2 = (m - d) / (k - 1);
  n2 += ((m - d) % (k - 1)) > 0;
  cout << d - n2 << "\n";

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