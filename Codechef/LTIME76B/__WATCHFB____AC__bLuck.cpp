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
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll x, y, z;
    cin >> x >> y >> z;
    ll a = 0, b = 0;
    if (x == 2 and y != z)
      cout << "NO"
           << "\n";
    else {
      cout << "YES"
           << "\n";
      a = y;
      b = z;
    }
    for (auto i = 1; i < n; i++) {
      cin >> x >> y >> z;
      if (x == 1 or y == z) {
        cout << "YES"
             << "\n";
        a = y;
        b = z;
      } else if (a + b == y + z) {
        cout << "YES"
             << "\n";

      } else if (a > y or a > z) {
        cout << "YES"
             << "\n";
        if (a > y) {
          a = z;
          b = y;
        } else {
          a = y;
          b = z;
        }
      } else if (b > y or b > z) {
        cout << "YES"
             << "\n";
        if (b > y) {
          b = z;
          a = y;
        } else {
          b = y;
          a = z;
        }
      } else {
        cout << "NO"
             << "\n";
      }
    }
  }
  return 0;
}