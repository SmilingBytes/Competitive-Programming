#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("help.txt", "w", stdout);
#endif
  IO int t;
  cin >> t;
  while (t--) {
    ll a, b, c, a1, b1, c1;
    cin >> a >> b >> c;
    cout << a << " " << b << " " << c << " => ";

    a1 = a;
    b1 = b;
    c1 = c;
    a %= 2;
    b %= 2;
    c %= 2;
    if (a == 0 && b == 0 && c == 0) {
      cout << "YES";
    } else if ((a == 0 && b == 0 && c == 1) || (a == 1 && b == 0 && c == 0)) {
      cout << "NO";
    } else if (a == 0 && b == 1 && c == 0) {
      if (a >= 2)
        cout << "YES";
      else
        cout << "NO";
    } else if ((a == 1 && b == 1 && c == 0) || (a == 0 && b == 1 && c == 1)) {
      cout << "NO";
    } else if (a == 1 && b == 0 && c == 1) {
      if ((a1 >= 2 && c1 >= 2) || (b1 >= 2))
        cout << "YES";
      else
        cout << "NO";
    } else {
      cout << "YES";
    }
    cout << endl;
  }
  return 0;
}