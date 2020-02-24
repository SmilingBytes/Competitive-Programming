#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";
const ll mod = 1000000007;
ll f[100001];
void fact() {
  f[0] = 1;
  f[1] = 1;
  for (register int i = 2; i <= 100000; i++) f[i] = (f[i - 1] * i) % mod;
}
void solve() {
  int n = 10000;
  string a, b;
  cin >> a >> b;
  int na1 = count(all(a), '1');
  int nb1 = count(all(b), '1');
  int na0 = n - na1, nb0 = n - nb1;
  int mx1 = na1 + nb1;
  if (mx1 > n) {
    int tmp = mx1 - n;
    mx1 = n - tmp;
  }
  int mn1 = min(na1, nb1) + min(na0, nb0);
  mn1 = n - mn1;
  ll ans = 0, tmp = 0;
  for (register int i = mx1; i >= mn1; i -= 2) {
    tmp = f[n] / ((f[i] * f[n - i]) % mod);
    ans = (ans + tmp) % mod;
  }
  // if (mx1 % 2 != mn1 % 2)
  // cout << "mx1 = " << mx1 << "\t mn1 = " << mn1 << "\n";
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  fact();
  string a = "123";
  do {
    std::cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
  } while (std::next_permutation(all(a)));
  // register int tc;
  // cin >> tc;
  // while (tc--) solve();
  return 0;
}