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
    int n, m, x, y, s;
    cin >> n >> m;
    cin >> x >> y >> s;
    int xx = 0, yy = 0;
    int d, prev = 0;
    while (x--) {
      cin >> d;
      xx += (d - prev - 1) / s;
      prev = d;
    }
    if ((n - prev) >= s) xx += (n - prev) / s;

    prev = 0;
    while (y--) {
      cin >> d;
      yy += (d - prev - 1) / s;
      prev = d;
    }
    if ((m - prev) >= s) yy += (m - prev) / s;

    if (x == 0) xx = n / s;
    if (y == 0) yy = m / s;
    cout << xx * yy << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}