/**
 *    author:  ismail
 *    created: 20.06.2020  20:51:24
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  int counter = 0;
  for (int i = n; i >= 1; i--) {
    int j = i;
    counter = 0;
    while (j <= n) {
      counter++;
      j += i;
      if (counter == 2) {
        cout << i << "\n";
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}