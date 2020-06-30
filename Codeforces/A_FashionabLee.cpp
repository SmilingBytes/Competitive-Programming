/**
 *    author:  ismail
 *    created: 23.06.2020  20:56:15
 **/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    cout << (n % 4 == 0 ? "YES" : "NO") << "\n";
  }

  return 0;
}