/**
 *    author:  ismail
 *    created: 19.01.2020  20:54:42
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
  int n;
  cin >> n;
  double ans = 0.0;
  for (int i = 1; i <= n; i++) {
    ans += (double)(1.0 / i);
  }
  cout.precision(12);
  cout << fixed << ans << "\n";

  return 0;
}