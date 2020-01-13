// https://codeforces.com/contest/1241/problem/A
/**
 *    author:  ismail
 *    created: 13.01.2020  01:38:56
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  ll n, ans;
  cin >> n;
  if (n < 4)
    ans = 4 - n;
  else
    ans = n % 2;
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