// https://codeforces.com/contest/1270/problem/C
/**
 *    author:  ismail
 *    created: 29.12.2019  20:58:59
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n;
  cin >> n;
  ll sm = 0, x = 0;
  cin >> sm;
  x = sm;
  for (int i = 1, d; i < n; i++) {
    cin >> d;
    sm += d;
    x ^= d;
  }
  if (sm == 2 * x) return cout << 0 << "\n\n", 0;
  ll add1 = x;
  sm += x;
  x ^= x;
  ll add2 = sm;
  cout << 2 << "\n";
  cout << add1 << " " << add2 << "\n";
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}