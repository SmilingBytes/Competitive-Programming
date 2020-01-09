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
    int n;
    cin >> n;
    int a[n];
    for (auto i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int x = 60, y = 75, z = 90, k = n / 4;
    int i = 1;
    bool flag = true;
    while (i < 4) {
      int index = i * k;
      if (a[index] == a[index - 1]) {
        flag = false;
        break;
      }
      if (i == 1) x = a[index];
      if (i == 2) y = a[index];
      if (i == 3) z = a[index];
      i++;
    }
    (flag) ? cout << x << " " << y << " " << z << "\n" : cout << -1 << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}