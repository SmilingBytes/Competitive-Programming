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
    ll n, q;
    cin >> n >> q;
    ll a[n], b[n];
    for (auto i = 0; i < n; i++) cin >> a[i];
    while (q--) {
      ll k;
      cin >> k;
      cout << "for k = " << k << "\n";

      for (auto i = 0; i < n; i++) b[i] = a[i] ^ k;
      for (const auto val : a) cout << val << " ";
      cout << "\n";

      for (const auto val : b) cout << val << " ";
      cout << "\n\n";

      // ll i = 0, ans = 0;
      // while (i < n - 1) {
      //   for (auto j = i + 1; j < n; j++)
      //     if (b[i] > b[j]) ans++;
      //   i++;
      // }
      // cout << ans << "\n";
    }
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}