#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

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
  cout.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  ll n, p, w, d, x, y, z;
  cin >> n >> p >> w >> d;
  if (n * w < p) return cout << -1 << "\n", 0;
  if (p == 0) return cout << 0 << " " << 0 << " " << n << "\n", 0;
  ll mx = p / w;
  ll minx = p / d;
  if (minx <= n and p % d == 0)
    return cout << 0 << " " << minx << " " << n - minx << "\n", 0;
  while (mx > 0) {
    ll dew = p - (mx * w);
    if (dew / d > n - mx) return cout << -1 << "\n", 0;
    if (dew == 0) {
      if (mx <= n) return cout << mx << " " << 0 << " " << n - mx << "\n", 0;
    }
    if (dew % d == 0) {
      ll md = dew / d;
      if (mx + md <= n)
        return cout << mx << " " << md << " " << n - mx - md << "\n", 0;
    }
    mx--;
  }
  cout << -1 << "\n";

#ifndef ONLINE_JUDGE
  std::cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}