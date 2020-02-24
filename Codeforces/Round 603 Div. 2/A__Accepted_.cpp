#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
const auto start_time = chrono::steady_clock::now();
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  ull a, b, c, m, n;
  cin >> a >> b >> c;
  m = max(a, max(b, c));
  n = min(a, min(b, c));
  ull mn = (a + b + c) - (m + n);
  ull ans = n;
  if (mn + n >= m) {
    ans = (m + n + mn) / 2;
    cout << ans << "\n";
    return 0;
  }
  m -= n;
  m = min(m, mn);
  ans += m;
  cout << ans << '\n';
  return 0;
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

  const auto _now = chrono::steady_clock::now();
  cerr << "\nTime elapsed: "
       << chrono::duration_cast<chrono::milliseconds>(_now - start_time).count()
       << " ms\n";
  return 0;
}