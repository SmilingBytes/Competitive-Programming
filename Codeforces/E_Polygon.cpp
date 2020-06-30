/**
 *    author:  ismail
 *    created: 28.06.2020  15:11:53
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  string a[n];

  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[i][j] == '1') {
        if (a[i + 1][j] == '0' and a[i][j + 1] == '0') {
          cout << "NO"
               << "\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}