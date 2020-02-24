#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  bool f = false;
  ll ans = 0, x = 0, y = 0;
  for (register int i = 0, d; i < n; i++) {
    cin >> d;
    ans += (d >> 1);
    if (d % 2 == 1) (i % 2 == 0) ? x++ : y++;
  }
  ans += min(x, y);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  solve();
  return 0;
}
