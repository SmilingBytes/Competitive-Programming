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
    ll n, k;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1' or s[n - 1] == '1') {
      cout << 2 * n << "\n";
      continue;
    }
    ll cnt = 0, fst = n + 1, lst = 0;
    for (ll i = 0; i < n; i++) {
      if (s[i] == '1') {
        fst = min(fst, i);
        lst = max(lst, i + 1);
        cnt++;
      }
    }
    if (cnt == 0) {
      cout << n << "\n";
      continue;
    }
    ll ans = n + cnt;
    ans = max(ans, (n - fst) * 2);
    ans = max(ans, 2 * lst);
    cout << ans << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}