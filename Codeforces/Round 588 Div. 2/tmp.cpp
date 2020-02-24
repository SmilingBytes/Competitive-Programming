#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
const int mod = 1e9 + 7;

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
  ll n, m;
  cin >> n >> m;

  if (n < 7 or m == 0) {
    cout << m << "\n";
    return 0;
  }
  ll a[8][8] = {0}, cnt[2][8] = {0};
  ll ans = m;
  for (auto i = 0; i < m; i++) {
    ll d1, d2;
    cin >> d1 >> d2;
    a[d1][d2] = 1;
    a[d2][d1] = 1;
    cnt[0][d1] += 1;
    cnt[0][d2] += 1;
  }
  sort(cnt[0], cnt[0] + 8);
  for (const auto val : cnt[0]) cout << val << " ";
  // if (a[cnt[n].ss][cnt[n - 1].ss] == 1) cnt[n - 1].ff -= 1;
  // if (cnt[n - 1].ff > 4) ans -= 1;
  // if ((cnt[1].ff - 1) > 0) ans -= (cnt[1].ff - 1);
  cout << ans + 1 << "\n";
  return 0;
}