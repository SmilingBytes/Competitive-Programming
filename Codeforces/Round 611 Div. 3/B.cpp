// https://codeforces.com/contest/1283/problem/B
/**
 *    author:  ismail
 *    created: 28.12.2019  23:13:56
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  ll n, k;
  cin >> n >> k;
  cout << ((n / k) * k) + min((n % k), (k / 2)) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}