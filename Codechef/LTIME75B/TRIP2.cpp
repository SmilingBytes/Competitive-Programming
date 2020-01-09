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

// if (k == 2) {
//   int cnt = 0;
//   for (auto i = 0; i < n; i++) {
//     if (a[i] == -1) {
//       cnt++;
//     } else if (cnt > 0) {
//       int fst = ((i - cnt - 1) < 0) ? 0 : a[i];
//       int lst =
//     }
//   }
// }
// }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    bool flag = true;
    int n, k = 2;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (auto val : a) cout << val << " ";
  }
  return 0;
}