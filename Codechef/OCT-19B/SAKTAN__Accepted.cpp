#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimization("O3")
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mll unordered_map<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n, m, q, x, y, a = 0, b = 0;
    cin >> n >> m >> q;
    mll row, col;
    for (auto i = 0; i < q; i++) {
      cin >> x >> y;
      row[x]++;
      col[y]++;
    }
    for (const auto val : row) a += val.ss % 2;
    for (const auto val : col) b += val.ss % 2;

    ll ans = (m - b) * a + (n - a) * b;
    cout << ans << "\n";
  }
  return 0;
}