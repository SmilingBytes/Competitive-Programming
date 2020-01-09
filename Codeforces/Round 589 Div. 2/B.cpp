#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const ll mod = 1e9 + 7;

#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll r, c, d, ans = 1;
  cin >> r >> c;
  int a[r + 2][c + 2];
  memset(a, -1, sizeof(a[0][0]) * (r + 2) * (c + 2));

  for (auto i = 1; i <= r; i++) {
    cin >> d;
    a[i][d + 1] = 0;
    for (auto j = 1; j <= d; j++) a[i][j] = 1;
  }

  for (auto i = 1; i <= c; i++) {
    cin >> d;
    if (a[d + 1][i] > 0) return cout << 0 << "\n", 0;
    a[d + 1][i] = 0;

    for (auto j = 1; j <= d; j++) {
      if (a[j][i] == 0) return cout << 0 << "\n", 0;
      a[j][i] = 1;
    }
  }

  for (auto i = 2; i <= r; i++)
    for (auto j = 2; j <= c; j++)
      if (a[i][j] == -1) ans = (ans * 2) % mod;

  return cout << ans << "\n", 0;
}