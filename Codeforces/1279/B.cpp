// https://codeforces.com/contest/1279/problem/B
/**
 *    author:  Smile.Forever
 *    created: 27.12.2019  20:59:34
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  ll n, s, sm = 0;
  cin >> n >> s;
  ll a[n], v[n], d = 0, mx = -1, pos = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (sm <= s) {
      d++;
      if (mx < a[i]) {
        mx = a[i];
        pos = i + 1;
      }
    }
    sm += a[i];
    v[i] = sm;
  }
  if (sm <= s)
    cout << 0 << "\n";
  else {
    if (pos < n) {
      ll dif = v[d] - a[pos];
      if (dif <= sm) cout << pos << "\n";
    } else
      cout << 0 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}