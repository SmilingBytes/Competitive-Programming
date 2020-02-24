/**
 *    author:  ismail
 *    created: 30.12.2019  18:36:14
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2);
  a[0] = a[n + 1] = -121;
  for (int i = 1; i <= n; i++) cin >> a[i];
  bool f = true;

  if (n == 1) {
    a[1] = (a[1] == -1) ? 1 : a[1];
  } else if (k == 2) {
    int i = 1;
    while (i <= n and a[i] == -1) i++;
    int pos = i;
    if (i == n + 1) {
      for (int i = 1; i <= n; i++) a[i] = ((i + 1) % 2) + 1;
    } else {
      while (i <= n) {
        if (a[i] == -1)
          a[i] = (a[i - 1] % 2) + 1;
        else if (a[i] == a[i - 1]) {
          f = false;
          break;
        }
        i++;
      }
      while (pos > 0 and f) {
        if (a[pos] == -1)
          a[pos] = (a[pos + 1] % 2) + 1;
        else if (a[pos] == a[pos + 1]) {
          f = false;
          break;
        }
        pos--;
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (a[i] == -1) {
        for (int j = 1; j <= k; j++) {
          if (a[i - 1] != j and a[i + 1] != j) {
            a[i] = j;
            break;
          }
        }
      }
    }
  }
  if (f) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}