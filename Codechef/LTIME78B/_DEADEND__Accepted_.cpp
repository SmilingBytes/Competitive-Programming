#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  int a[n + 2];
  a[0] = a[n + 1] = -1;
  for (register int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + (n + 1));
  for (const auto val : a) cout << val << " ";
  cout << "\n";
  int ans = 0;
  for (register int i = 1; i <= n; i++) {
    if (a[i] + 1 != a[i + 1] and a[i] - 1 != a[i - 1]) {
      ans++;
      a[i] += 1;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("hin.txt", "w", stdout);
#endif

  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}