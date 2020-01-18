#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  map<int, bool> mp;
  for (register int i = 0, d; i < n; i++) {
    cin >> d;
    if (d % 2 == 0 and !mp[d]) mp[d] = true;
  }
  ll ans = 0;
  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    int x = it->first;
    x /= 2;
    ans++;
    if (x % 2 == 0) mp[x] = true;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}