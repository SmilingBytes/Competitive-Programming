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

  if (n < 7 or m < 10) return cout << m, 0;
  if (m == 21) return cout << 16, 0;
  ll a[8][8] = {0};
  vector<pll> cnt(n + 1, std::make_pair(0, 0));
  ll ans = m, d1, d2;
  for (auto i = 0; i < m; i++) {
    cin >> d1 >> d2;
    a[d1][d2] = 1;
    cnt[d1] = (make_pair(cnt[d1].ff + 1, d1));
    cnt[d2] = (make_pair(cnt[d2].ff + 1, d2));
  }
  sort(all(cnt));
  if (a[cnt[n].ss][cnt[n - 1].ss] == 1 or a[cnt[n - 1].ss][cnt[n].ss] == 1)
    cnt[n - 1].ff -= 1;
  for (const auto val : cnt) cout << val.ff << " <= " << val.ss << "\n";
  if (cnt[n - 1].ff > 4) ans -= 1;
  if ((cnt[1].ff - 1) > 0) ans -= (cnt[1].ff - 1);
  cout << ans << "\n";

  return 0;
}