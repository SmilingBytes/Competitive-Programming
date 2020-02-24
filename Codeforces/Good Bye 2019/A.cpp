// https://codeforces.com/contest/1270/problem/A
/**
 *    author:  ismail
 *    created: 29.12.2019  20:33:12
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, k1, k2;
  cin >> n >> k1 >> k2;
  int mx1 = 0, mx2 = 0;
  for (int i = 0, d; i < k1; i++) {
    cin >> d;
    if (d > mx1) mx1 = d;
  }
  for (int i = 0, d; i < k2; i++) {
    cin >> d;
    if (d > mx2) mx2 = d;
  }
  cout << (mx1 > mx2 ? "YES\n" : "NO\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}