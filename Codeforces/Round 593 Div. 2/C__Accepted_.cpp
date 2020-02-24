#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n + 1][n + 1];
  bool f = true;
  int d = 1;
  for (auto i = 1; i <= n; i++) {
    if (f) {
      for (auto j = 1; j <= n; j++) a[j][i] = d++;
      f = false;
    } else {
      for (auto j = n; j > 0; j--) a[j][i] = d++;
      f = true;
    }
  }

  for (auto i = 1; i <= n; i++) {
    for (auto j = 1; j <= n; j++) cout << a[i][j] << " ";
    cout << "\n";
  }
}