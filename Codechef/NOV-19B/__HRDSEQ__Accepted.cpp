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

  int a[130], c[130], p[130], ans[130];
  memset(c, 0, sizeof(c));
  memset(p, 0, sizeof(p));
  memset(ans, 0, sizeof(ans));
  a[1] = 0;
  for (auto i = 1; i < 129; i++) {
    (c[a[i]] == 0) ? a[i + 1] = 0 : a[i + 1] = i - p[a[i]];
    c[a[i]]++;
    p[a[i]] = i;
    ans[i] = c[a[i]];
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ans[n] << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}