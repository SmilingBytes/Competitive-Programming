#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

typedef long long ll;
const int mod = 1e9 + 7;
#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
    ll n, k, p;
    cin >> n >> k >> p;
    ll ans = 0;
    register ll a;
    if (k % 2 == 1) {
      ll mx = 0;
      ll mn = 1e9;
      for (auto i = 0; i < n; i++) {
        cin >> a;
        mx = max(mx, a);
        mn = min(mn, a);
      }
      if (p == 0)
        cout << mx << "\n";
      else
        cout << mn << "\n";
    } else {
      ll b[n + 2];
      for (auto i = 1; i <= n; i++) cin >> b[i];

      if (p == 0) {
        ll mx1 = 0, mx2 = 0, index = 0, mx = 0;
        mx = max(b[2], b[n - 1]);
        mx2 = mx;
        for (auto i = 2; i < n; i++) {
          if (b[i - 1] > mx and b[i + 1] > mx) {
            if (b[i - 1] >= b[i + 1] and b[i + 1] > mx1) {
              mx1 = b[i + 1];
              mx2 = b[i - 1];
            } else if (b[i - 1] <= b[i + 1] and b[i - 1] > mx1) {
              mx1 = b[i - 1];
              mx2 = b[i + 1];
            }
          }
        }
        cout << max(mx, mx1) << "\n";
      } else {
        ll mn1 = INF, mn2 = INF, mn = INF;
        mn = min(b[2], b[n - 1]);
        mn2 = mn;
        for (auto i = 2; i < n; i++) {
          if (b[i - 1] < mn and b[i + 1] < mn) {
            if (b[i - 1] <= b[i + 1] and b[i + 1] < mn1) {
              mn1 = b[i + 1];
              mn2 = b[i - 1];
            } else if (b[i - 1] >= b[i + 1] and b[i - 1] < mn1) {
              mn1 = b[i - 1];
              mn2 = b[i + 1];
            }
          }
        }
        cout << min(mn, mn1) << "\n";
      }
    }
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}