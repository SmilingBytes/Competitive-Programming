#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  ull n, m, ans = 0;
  cin >> n >> m;
  for (register int i = 0, num; i < n; i++) {
    cin >> num;
    ans += (2 * num);
  }
  if (n == 2 or n > m) return cout << -1 << endl, 0;
  cout << ans << endl;
  for (register int i = 1; i < n; i++) cout << i << " " << i + 1 << endl;
  cout << n << " " << 1 << "\n";
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}