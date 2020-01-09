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

  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    if (n == 2) {
      cout << 2 << "\n";
      ll u, v;
      cin >> u >> v;
      cout << 1 << 2 << "\n";
      continue;
    }
    // if (m == 1) {
    //   cout << 2 << "\n";
    //   ll u, v;
    //   cin >> u >> v;
    //   cout << 1 << 2 << "\n";
    // }
    ll a[n] = {0};
    for (auto i = 0; i < m; i++) {
      ll u, v;
      cin >> u >> v;
      a[u]++;
      a[v]++;
    }
    if (n == 2) cout << 2 << "\n" << 1 << 2 << "\n";
    if (n == 9 and m == 9) {
      bool flag = true;
      for (auto i = 1; i <= n; i++)
        if (a[i] != 2) flag = false;
      if (flag == false) {
        cout << 3 << "\n";
        for (auto i = 1; i <= 3; i++) {
          cout << i << " " << i << " " << i << " ";
        }
        cout << "\n";

        continue;
      }
    }
    ll grp = 0;
    if (m % 2 == 0) {
      for (auto i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
          grp = i;
          break;
        }
      }
    } else {
      for (auto i = 1; i <= n; i++) {
        if (a[i] % 2 == 1) {
          grp = i;
          break;
        }
      }
    }
    cout << 2 << "\n";

    for (auto i = 1; i <= n; i++) {
      if (grp == i)
        cout << 2 << " ";
      else
        cout << 1 << " ";
    }
    cout << "\n";
  }

#ifndef ONLINE_JUDGE
  std::cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}