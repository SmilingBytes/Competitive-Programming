#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, a, b, c, r;
  cin >> a >> b >> c >> r;
  int l = c - r, rr = c + r;
  if (a > b) swap(a, b);
  int ans = 0;
  int dif = b - a;
  if (b <= l)
    cout << dif << "\n";
  else if (a >= rr)
    cout << dif << "\n";
  else {
    if (a < l) ans = l - a;
    if (b > rr) ans += (b - rr);
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}