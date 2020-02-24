#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

int nCr(int n, int r) {
  long long p = 1, k = 1;
  if (n - r < r) r = n - r;
  if (r != 0) {
    while (r) {
      p *= n;
      k *= r;
      long long m = __gcd(p, k);
      p /= m;
      k /= m;
      n--;
      r--;
    }
  } else
    p = 1;
  return p;
}

void solve() {
  int n;
  cin >> n;
  int a[3];
  memset(a, 0, sizeof(a));
  for (register int i = 0, num; i < n; i++) {
    cin >> num;
    if (num == 0 or num == 2) a[num]++;
  }
  int ans = 0;
  if (a[0] > 1) ans = nCr(a[0], 2);
  if (a[2] > 1) ans += nCr(a[2], 2);
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