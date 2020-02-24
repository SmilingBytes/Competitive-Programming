// https://codeforces.com/contest/1279/problem/C
/**
 *    author:  Smile.Forever
 *    created: 27.12.2019  21:53:31
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, m, pos = 0;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  ll ans = 0;
  unordered_multiset<int> mp;
  for (int i = 0; i < m; i++) {
    if (mp.find(b[i]) != mp.end()) {
      ans++;
      mp.erase(b[i]);
    } else {
      for (int j = pos; j < n; j++) {
        if (b[i] == a[j]) {
          ans++;
          ans += mp.size() + mp.size();
          pos = j + 1;
          break;
        } else {
          mp.insert(a[j]);
        }
      }
    }
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