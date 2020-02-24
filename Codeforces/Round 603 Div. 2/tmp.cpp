#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  register int n;
  cin >> n;
  bool mp[n + 2];
  memset(mp, false, sizeof(mp));
  vector<int> ans;
  ans.push_back(0);
  ans.push_back(1);
  mp[0] = true;
  mp[1] = true;
  register int d;
  for (register int i = (n / 2); i > 0; i--) {
    d = n / i;
    if (!mp[d]) {
      ans.push_back(d);
      mp[d] = true;
    }
  }
  cout << sz(ans) << "\n";
  for (const auto x : ans) cout << x << " ";
  std::cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}