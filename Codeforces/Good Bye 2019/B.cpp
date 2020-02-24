// https://codeforces.com/contest/1270/problem/B
/**
 *    author:  ismail
 *    created: 29.12.2019  20:43:04
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  bool f = true;
  for (int i = 1, dif; i < n; i++) {
    dif = abs(a[i] - a[i - 1]);
    if (dif >= 2) {
      f = false;
      cout << "YES\n";
      cout << i << " " << i + 1 << "\n";
      break;
    }
  }
  if (f) cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}