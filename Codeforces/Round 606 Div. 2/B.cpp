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
  for (register int i = 0, num; i < n; i++) {
    cin >> num;
    if (num % 2 == 0 and !mp[num]) mp[num] = true;
  }
  ll ans = 0;
  for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
    int num = it->first;
    num /= 2;
    ans++;
    if (num % 2 == 0) mp[num] = true;
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