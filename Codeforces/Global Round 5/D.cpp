#include <bits/stdc++.h>

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
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  ll n;
  cin >> n;
  double a[n];
  ll mx = 1e10;
  ll mn = 0;
  for (auto i = 0; i < n; i++) cin >> a[i];

  ll i = 0;
  while (i < n) {
    ll j = i + 1;
    ll cnt = 1;
    double p = a[i] / 2.0;
    while (j < 3 * (n - 1)) {
      if (p) p = max(a[j] / 2.0, p);
    }
    if (j == 3 * (n - 1)) {
      for (auto k = 0; k < n; k++) cout << -1 << " ";
      break;
    }
  }
  return 0;
}