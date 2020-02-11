#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
const int mod = 1e9 + 7;

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    // cout << a << " " << b << " " << c << " => ";
    if ((a + c) % 2 == 0) {
      if (a > 0 and b > 0 and c > 0)
        cout << "YES"
             << "\n";
      else if ((a + b == 0 or a + c == 0 or b + c == 0) and
               ((a + b + c) % 2 == 0)) {
        cout << "YES"
             << "\n";

      } else if (a == 0 and b > 1) {
        cout << "YES"
             << "\n";
      } else if (b == 0 and a > 1) {
        cout << "YES"
             << "\n";
      } else if (c == 0) {
        cout << "YES"
             << "\n";
      } else {
        cout << "NO"
             << "\n";
      }

    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}