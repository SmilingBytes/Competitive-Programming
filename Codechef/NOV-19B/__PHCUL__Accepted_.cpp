#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
const ull mod = 1e9 + 7;
#define INF 1000000000

#define ff first
#define ss second
#define pii pair<ull, ull>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

struct pt {
  ull x, y;
};

inline dbl dist(pt p1, pt p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

inline dbl min(dbl x, dbl y) { return (x < y) ? x : y; }

dbl minDist(pt p, pt *arr, ull n) {
  register dbl dis = 1e18;
  for (register ull i = 0; i < n; i++) dis = min(dis, dist(p, arr[i]));
  return sqrt(dis);
}

dbl totalDist(pt p, pt *arr, ull n, dbl *add) {
  register dbl dis = 1e18;
  for (register ull i = 0; i < n; i++) {
    dbl d = sqrt(dist(p, arr[i])) + add[i];
    dis = min(dis, d);
  }
  return dis;
}

dbl minPath(pt p, pt *a, ull n, pt *b, ull m, dbl *dis, bool f) {
  dbl ans;
  ans = 1e18;
  for (register ull i = 0; i < n; i++) {
    dbl md = totalDist(a[i], b, m, dis);
    dbl dd = sqrt(dist(p, a[i]));
    ans = min(ans, (md + dd));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);

#ifndef ONLINE_JUDGE
  ull begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
    register ull n, m, k;
    pt p;
    cin >> p.x >> p.y >> n >> m >> k;
    pt a[n], b[m], c[k];
    dbl dac[n], dbc[m];
    for (register ull i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    for (register ull i = 0; i < m; i++) cin >> b[i].x >> b[i].y;
    for (register ull i = 0; i < k; i++) cin >> c[i].x >> c[i].y;

    dbl ans = 1e18;
    if (n <= 100 and m <= 100 and k <= 100) {
      for (register ull i = 0; i < n; i++) {
        dbl db = 1e18;
        for (register ull j = 0; j < m; j++) {
          dbl tm = sqrt(dist(a[i], b[j]));
          dbl dc = 1e18;
          for (register ull kk = 0; kk < k; kk++) {
            dbl tmp = dist(b[j], c[kk]);
            dc = min(dc, tmp);
          }
          db = min(db, (tm + sqrt(dc)));
        }
        dbl da = sqrt(dist(p, a[i])) + db;
        ans = min(ans, da);
      }

      for (register ull i = 0; i < m; i++) {
        dbl db = 1e18;
        for (register ull j = 0; j < n; j++) {
          dbl tm = sqrt(dist(b[i], a[j]));
          dbl dc = 1e18;
          for (register ull kk = 0; kk < k; kk++) {
            dbl tmp = dist(a[j], c[kk]);
            dc = min(dc, tmp);
          }
          db = min(db, (tm + sqrt(dc)));
        }
        dbl da = sqrt(dist(p, b[i])) + db;
        ans = min(ans, da);
      }
    } else {
      for (register ull i = 0; i < n; i++) dac[i] = minDist(a[i], c, k);
      for (register ull i = 0; i < m; i++) dbc[i] = minDist(b[i], c, k);

      dbl ans1 = minPath(p, a, n, b, m, dbc, true);
      dbl ans2 = minPath(p, b, m, a, n, dac, true);
      ans = min(ans1, ans2);
    }
    cout << fixed << ans << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}