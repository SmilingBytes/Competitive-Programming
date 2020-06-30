/**
 *    author:  ismail
 *    created: 17.06.2020  11:48:36
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n, odd = 0;
  cin >> n;
  vector<int> missloc[2];
  for (int i = 0, d; i < n; i++) {
    cin >> d;
    d %= 2;
    if (i % 2 != d) missloc[d].push_back(i);
  }
  if (missloc[0].size() != missloc[1].size()) return cout << -1 << "\n", 0;

  cout << missloc[0].size() << '\n';
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