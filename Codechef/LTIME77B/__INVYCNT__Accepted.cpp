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
    ll n, k;
    cin >> n >> k;
    int a[2 * n];
    int fst[n] = {0};
    for (auto i = 0; i < n; i++) cin >> a[i];
    int i = 0;
    while (i < n - 1) {
      for (auto j = i + 1; j < n; j++)
        if (a[i] > a[j]) fst[i]++;
      i++;
    }
    int dif[n] = {0};
    for (auto i = n; i < 2 * n; i++) a[i] = a[i - n];

    i = 0;
    while (i < n) {
      int j = n;
      while (j < 2 * n) {
        if (a[i] > a[j]) dif[i]++;
        j++;
      }
      i++;
    }
    ll ans = 0;
    if (k == 1)
      for (const auto val : fst) ans += val;
    else if (k > 1) {
      int i = 0;
      for (const auto d : dif) {
        ans += (k * (d * (k - 1) + fst[i] * 2)) / 2;
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