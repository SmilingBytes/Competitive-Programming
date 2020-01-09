#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimization("O3")
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
  freopen("out.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (auto i = 0; i < n; i++) cin >> a[i];
    // cout << n << " " << k << " = ";
    // for (const auto val : a) cout << val << " ";
    // cout << "===> ";
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }

    ll i = 0, j = 0;
    while (i < k and i < 3 * n) {
      j = i % n;
      a[j] ^= a[n - j - 1];
      i++;
    }
    if (k > 3 * n) {
      k = k % (3 * n);
      i = 0;
      while (i < k) {
        j = i % n;
        a[j] ^= a[n - j - 1];
        i++;
      }
    }
    for (const auto val : a) cout << val << " ";
    cout << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}