#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  string a, b;
  a = "000";
  b = "111";
  int n = sz(a);
  ll sma = 0, smb = 0;
  for (register int i = 0; i < n; i++) {
    sma += a[i] - '0';
    smb += b[i] - '0';
  }
  ll dif = smb - sma;
  cout << dif << "\n";

  // cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  solve();
  return 0;
}