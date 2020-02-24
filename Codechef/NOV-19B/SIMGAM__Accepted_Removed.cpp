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
#define w(a) std::cerr << #a << " : " << (a) << "\n";

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
    unsigned long long ans = 0;
    int c, tmp;
    vector<int> odd;
    while (n--) {
      cin >> c;
      int lim = c / 2;
      if (c & 1) {
        for (auto i = 0; i < c; i++) {
          cin >> tmp;
          if (i < lim)
            ans += tmp;
          else if (i == lim)
            odd.push_back(tmp);
        }
      } else {
        while (c--) {
          cin >> tmp;
          if (c >= lim) ans += tmp;
        }
      }
    }
    sort(all(odd));
    reverse(all(odd));
    for (auto i = 0; i < sz(odd); i += 2) ans += odd[i];
    std::cout << ans << "\n";
  }

#ifndef ONLINE_JUDGE
  std::cout << "\nTime elapsed: " << clock() - begtime << " ms\n";
#endif
  return 0;
}