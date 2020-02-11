/**
 *    author:  ismail
 *    created: 09.02.2020  20:07:26
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
    ll n, cnt = 0, sm = 0;
    cin >> n;
    for (int i = 0, d; i < n; i++) {
      cin >> d;
      sm += d;
      if (d == 0) cnt++;
    }
    if (sm + cnt == 0) cnt++;
    cout << cnt << "\n";
  }
  return 0;
}