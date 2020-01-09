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
  register int nn = sqrt(n);
  if (n < 3) {
    cout << n + 1 << "\n";
    for (register int i = 0; i <= n; i++) cout << i << " ";
  } else if (n / nn != nn) {
    cout << 2 * nn + 1 << "\n0 ";
    int ans[nn];
    for (register int i = 1; i <= nn; i++) {
      cout << i << " ";
      ans[i - 1] = n / i;
    }
    for (register int i = nn - 1; i >= 0; i--) cout << ans[i] << " ";

  } else {
    int ans[nn];
    cout << 2 * nn << "\n0 ";
    for (register int i = 1; i <= nn; i++) {
      cout << i << " ";
      ans[i - 1] = n / i;
    }
    for (register int i = nn - 2; i >= 0; i--) cout << ans[i] << " ";
  }
  cout << "\n";
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