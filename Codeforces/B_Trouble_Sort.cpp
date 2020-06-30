/**
 *    author:  ismail
 *    created: 07.06.2020  21:39:10
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, f;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];

  string ans = "No";
  cin >> f;
  for (int i = 1, d; i < n; i++) {
    cin >> d;
    if (f != d) ans = "Yes";
  }
  if (ans == "No") {
    bool f = true;
    for (int i = 1; i < n and f; i++) f = !(a[i] < a[i - 1]);
    if (f) ans = "Yes";
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}