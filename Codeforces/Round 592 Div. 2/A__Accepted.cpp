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
    ll a, b, c, d, k, x, y;
    cin >> a >> b >> c >> d >> k;
    if (a <= c)
      x = 1;
    else {
      x = a / c;
      if (a % c != 0) x++;
    }
    if (b <= d)
      y = 1;
    else {
      y = b / d;
      if (b % d != 0) y++;
    }
    if (x + y > k)
      cout << -1 << "\n";
    else {
      cout << x << " " << y << "\n";
    }
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}