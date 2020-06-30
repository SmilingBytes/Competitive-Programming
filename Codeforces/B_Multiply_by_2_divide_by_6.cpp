/**
 *    author:  ismail
 *    created: 28.06.2020  20:54:31
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, cnt = 0;
  cin >> n;
  while (n > 1) {
    int rem = n % 6;
    if (rem == 0) {
      n /= 6;
    } else if (rem == 3) {
      n *= 2;
    } else {
      break;
    }
    cnt++;
  }

  cout << (n == 1 ? cnt : -1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}