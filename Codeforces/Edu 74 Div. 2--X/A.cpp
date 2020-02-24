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

void run() {
  ll a, b;
  cin >> a >> b;
  if (a - b == 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) run();
  return 0;
}