#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
const int mod = 1e9 + 7;

#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(x) cout << #x << " = " << (x) << "\n"

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n;
    string a, b;
    cin >> a >> b;

    if (n == 1) {
      (a[0] <= 2 or b[0] <= 2) ? cout << "NO"
                                      << "\n"
                               : cout << "YES"
                                      << "\n";
      continue;
    }

    bool flag = true, ans = true;
    for (auto i = 0; i < n; i++) {
      if (i != n - 2) {
        if (flag and (a[i] > '2')) {
          if (b[i] <= '2') {
            ans = false;
            break;
          }
          flag = !flag;
        } else if (!flag and (b[i] > '2')) {
          if (a[i] <= '2') {
            ans = false;
            break;
          }
          flag = !flag;
        }
      } else {
        if (flag) {
          if (a[i] <= '2' and (a[i + 1] <= '2')) {
            ans = false;
            break;
          } else if (a[i] > '2' and (b[i] <= '2' or b[i + 1] > '2')) {
            ans = false;
            break;
          }
        } else {
          if (b[i] <= '2' and b[i + 1] > '2') {
            ans = false;
            break;
          } else if (b[i] > '2' and (a[i] <= '2' or a[i + 1] <= '2')) {
            ans = false;
            break;
          }
        }
      }
    }

    (ans) ? cout << "YES"
                 << "\n"
          : cout << "NO"
                 << "\n";
  }
  return 0;
}