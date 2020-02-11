/**
 *    author:  ismail
 *    created: 09.02.2020  15:10:59
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    if (n < 10) {
      cout << n << "\n";
    } else {
      ll ans = 0ll + n;
      while (n > 9) {
        int d = n / 10;
        n = n % 10;
        n += d;
        ans += d;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}