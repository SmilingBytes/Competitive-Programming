/**
 *    author:  ismail
 *    created: 20.01.2020  22:00:58
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
  int n, m, ans = 1;
  cin >> n >> m;
  for (int i = 1, d; i < n; i++) {
    cin >> d;
    if (d <= m) {
      ans++;
      m = d;
    }
  }
  cout << ans << "\n";

  return 0;
}