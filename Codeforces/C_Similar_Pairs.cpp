/**
 *    author:  ismail
 *    created: 28.06.2020  14:18:00
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);

  int even = 0, odd = 0;
  for (auto x : a) (x & 1) ? odd++ : even++;
  if (!(even & 1)) {
    cout << "YES\n";
    return;
  } else {
    for (int i = 1; i < n; i++) {
      if (abs(a[i] - a[i - 1]) == 1) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}