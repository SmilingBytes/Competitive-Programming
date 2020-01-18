#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  string a[n], s;
  unordered_map<string, bool> zz, oo, zo, oz;
  for (register int i = 0; i < n; i++) {
    cin >> s;
    int ln = sz(s);
    char f = s[0];
    char l = s[ln - 1];
    if (f == '0' and l == '0') {
      zz[s] = true;
    } else if (f == '1' and l == '1') {
      oo[s] = true;
    } else if (f == '1' and l == '0') {
      oz[s] = true;
    } else if (f == '0' and l == '1') {
      zo[s] = true;
    }
  }
  int n00, n11, n10, n01;
  n11 = sz(oo);
  n10 = sz(oz);
  n01 = sz(zo);
  n00 = sz(zz);

  // cout << ans << '\n';
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