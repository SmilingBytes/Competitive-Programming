#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define w(a) cerr << #a << " : " << (a) << "\n";

void solve() {
  ll a, b;
  cin >> a >> b;
  if (a == b) cout << "=\n";
  if (a < b) cout << "<\n";
  if (a > b) cout << ">\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}