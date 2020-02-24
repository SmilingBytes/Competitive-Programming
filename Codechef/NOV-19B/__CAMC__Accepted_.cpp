#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

typedef long long ll;
typedef unsigned long long ull;
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
    register int n, m, d;
    cin >> n >> m;
    int a[n];
    int ans = 1e9;
    if (m == n) {
      register int mn = 1e9, mx = -1;
      for (register int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > mx) mx = a[i];
        if (a[i] < mn) mn = a[i];
      }
      ans = mx - mn;
    } else {
      for (register int i = 0; i < n; i++) cin >> a[i];

      int lim = (n / m);
      if (n % m != 0) lim += 1;
      int box[m][lim];
      memset(box, -1, sizeof box);
      int bound = 1e9;
      for (register int i = 0; i < m; i++) {
        register int j = i, ii = 0;
        while (j < n) {
          box[i][ii] = a[j];
          j += m;
          ii++;
        }
        sort(box[i], box[i] + lim);
        bound = min(bound, box[i][lim - 1]);
      }

      sort(a, a + n);
      register int i = 0;
      while (i < n and a[i] <= bound) {
        register int p = a[i], d = 0;
        for (register int j = 0; j < m; j++) {
          auto dif = lower_bound(box[j], box[j] + lim, p);
          d = max(d, (*dif - p));
          if (d > ans) break;
        }
        ans = min(ans, d);
        i++;
      }
    }
    cout << ans << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}