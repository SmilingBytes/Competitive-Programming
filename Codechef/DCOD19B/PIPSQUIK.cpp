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

  int q;
  cin >> q;
  while (q--) {
    int n, h, y1, y2, life;
    cin >> n >> h >> y1 >> y2 >> life;
    int ans = 0;
    bool flag = true;
    while (n--) {
      int t, x;
      cin >> t >> x;
      if (life > 1) {
        ans++;
        if (t == 1 and h - y1 > x)
          life--;
        else if (t == 2 and y2 < x)
          life--;
      } else if (flag)
        if (t == 1) {
          (h - y1 <= x) ? ans++ : flag = false;
        } else {
          (y2 >= x) ? ans++ : flag = false;
        }
    }
    cout << ans << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}