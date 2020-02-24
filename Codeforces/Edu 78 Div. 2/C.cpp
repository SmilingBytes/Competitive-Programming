#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n = 8;
  int v[n];
  for (register int i = 0; i < n; i++) {
    v[i] = i * 2;
  }
  // 0,2,4,6,8,10,12
  // auto upb = upper_bound(v, v + n, 3);
  auto lpb = lower_bound(v, v + n, 11);
  std::cout << "lower_bound of 3 = " << lpb - (v + 0) << '\n';
  // std::cout << "upper_bound of 3 = " << upb - v.begin() << '\n';
  // cout << ans << '\n';
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