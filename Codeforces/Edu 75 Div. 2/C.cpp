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
    string a;
    cin >> a;
    string s[2];
    for (auto x : a) s[(int)(x - '0') & 1] += x;
    reverse(all(s[0]));
    reverse(all(s[1]));
    string ans = "";

    while (!(s[0].empty() and s[1].empty())) {
      if (s[0].empty()) {
        ans += s[1].back();
        s[1].pop_back();
      } else if (s[1].empty()) {
        ans += s[0].back();
        s[0].pop_back();
      } else if (s[0].back() < s[1].back()) {
        ans += s[0].back();
        s[0].pop_back();
      } else {
        ans += s[1].back();
        s[1].pop_back();
      }
    }
    cout << ans << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}