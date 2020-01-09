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
  freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  cin >> n;
  register ll tmp;
  vector<pll> a;
  for (auto i = 0; i < n; i++) {
    cin >> tmp;
    a.push_back(make_pair(tmp, i));
  }
  sort(all(a));
  ll x = 0;
  ll b[n];
  ll ans = 0;
  int j = 0;
  for (auto i = n - 1; i >= 0; i--) {
    b[j++] = a[i].ss;
    ans += a[i].ff * x + 1;
    x++;
  }
  cout << ans << "\n";
  for (const auto val : b) cout << val + 1 << " ";
  return 0;
}