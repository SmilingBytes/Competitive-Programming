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
    ll n;
    register string s, t, ss = "", tt = "";
    cin >> n >> s >> t;
    ll cnt = 0;
    string ans = "Yes";
    for (register int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        ss += s[i];
        tt += t[i];
        cnt++;
        if (cnt > 2) {
          ans = "No";
          break;
        }
      }
    }

    if (cnt == 1) {
      ans = "No";
    } else if (cnt == 2 and (ss[0] != ss[1] or tt[0] != tt[1])) {
      ans = "No";
    }
    cout << ans << "\n";
  }
#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}