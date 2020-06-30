/**
 *    author:  ismail
 *    created: 09.05.2020  21:15:03
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n, k;
  cin >> n >> k;
  if (k > n) return cout << "NO\n", 0;
  if (n & 1) {
    if (k & 1) {
      cout << "YES\n" << n - (k - 1);
      while (k > 1) {
        cout << " " << 1;
        k--;
      }
    } else
      cout << "NO";

  } else {
    if (k & 1) {
      if (n / 2 >= k) {
        cout << "YES\n" << n - (k - 1) * 2;
        while (k > 1) {
          cout << " " << 2;
          k--;
        }
      } else {
        cout << "NO";
      }
    } else {
      if (n >= k) {
        cout << "YES\n" << n - (k - 1);
        while (k > 1) {
          cout << " " << 1;
          k--;
        }
      } else
        cout << "NO";
    }
  }
  cout << '\n';
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