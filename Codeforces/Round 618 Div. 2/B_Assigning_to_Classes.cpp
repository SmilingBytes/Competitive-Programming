/**
 *    author:  ismail
 *    created: 09.02.2020  20:19:06
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
    ll tn = 2 * n;
    int a[tn];
    for (int i = 0; i < tn; i++) cin >> a[i];
    sort(a, a + tn);
    int ans = a[n] - a[n - 1];
    cout << ans << "\n";
  }
  return 0;
}
