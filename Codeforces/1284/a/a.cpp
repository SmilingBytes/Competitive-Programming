/**
 *    author:  ismail
 *    created: 19.01.2020  03:55:09
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
  int n, m;
  cin >> n >> m;
  string sn[n], sm[m];
  for (int i = 0; i < n; i++) cin >> sn[i];
  for (int i = 0; i < m; i++) cin >> sm[i];
  int tc;
  cin >> tc;
  while (tc--) {
    int year;
    cin >> year;
    int ni = year % n, mi = year % m;
    if (ni == 0) ni = n;
    if (mi == 0) mi = m;
    string ans = sn[ni - 1] + sm[mi - 1];
    cout << ans << "\n";
    }

  return 0;
}