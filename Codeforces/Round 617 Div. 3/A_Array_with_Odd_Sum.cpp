/**
 *    author:  ismail
 *    created: 09.02.2020  14:57:56
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
    int odd = 0;
    for (int i = 0, d; i < n; i++) {
      cin >> d;
      if (d & 1) odd++;
    }
    int even = n - odd;
    if (odd == 0 or (even == 0 and n % 2 == 0))
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}