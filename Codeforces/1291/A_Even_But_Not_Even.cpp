/**
 *    author:  ismail
 *    created: 02.02.2020  20:05:12
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
    ll n;
    cin >> n;
    vector<int> a;
    string s;
    cin >> s;
    for (int i = 0, d; i < n; i++) {
      d = s[i] - '0';
      if (d % 2) {
        a.push_back(d);
        if (sz(a) >= 2) break;
      }
    }
    if (sz(a) < 2) {
      cout << -1 << "\n";
    } else {
      cout << a[0] << a[1] << "\n";
    }
    a.clear();
  }
  return 0;
}