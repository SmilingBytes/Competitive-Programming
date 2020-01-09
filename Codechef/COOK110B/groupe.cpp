#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out_ac.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << a << " " << b << " " << c << " => ";

    if ((a + c) % 2 == 0) {
      if (a > 0 and b > 0 and c > 0)
        cout << "YES"
             << "\n";
      else if (a + b == 0 or a + c == 0 or b + c == 0) {
        if ((a + b + c) % 2 == 0) {
          cout << "YES"
               << "\n";
        } else {
          cout << "NO"
               << "\n";
        }
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