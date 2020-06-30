/**
 *    author:  ismail
 *    created: 07.06.2020  20:39:37
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n, m, row = 0, col = 0;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    int f = 0;
    for (int j = 0, d; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) f = 1;
    }
    if (f == 0) row++;
  }

  for (int j = 0; j < m; j++) {
    int f = 0;
    for (int i = 0; i < n; i++) {
      if (a[i][j] == 1) f = 1;
    }
    if (f == 0) col++;
  }
  int unc = min(row, col);
  cout << ((unc % 2 == 1) ? "Ashish" : "Vivek") << '\n';
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