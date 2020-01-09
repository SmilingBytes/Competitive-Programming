#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  ll n, k;
  cin >> n;
  ll a[n], b[n];
  for (auto i = 0; i < n; i++) cin >> a[i];
  for (auto i = 0; i < n; i++) cin >> b[i];
  bool f[n];
  ll ans = 0;
  memset(f, false, sizeof f);
  ll i = 0, j = 0;
  while (i < n and j < n) {
    if (f[a[i]] == true) {
      i++;
    } else if (a[i] == b[j]) {
      i++;
      j++;
    } else {
      f[b[j]] = true;
      j++;
      ans++;
    }
  }
  std::cout << ans << "\n";
  return 0;
}