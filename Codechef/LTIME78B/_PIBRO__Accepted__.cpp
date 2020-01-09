#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int m = 0, cnt = 0, st = 0, end = 0, ans = 0, dis = 0;
  for (register int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cnt++;
    } else {
      st = i - cnt;
      end = n - i;
      if (end <= k) {
        dis = max(st, end);
        dis = min(k, dis);
        dis += cnt;
      } else {
        int j = i + k, inc = 0;
        while (j < n and s[j] != '0') {
          inc++;
          j++;
        }
        dis = cnt + k + inc;
      }
      ans = max(ans, dis);
      cnt = 0;
    }
  }
  if (cnt) {
    st = n - cnt;
    dis = min(k, st);
    dis = dis + cnt;
    ans = max(ans, dis);
  }
  std::cout << ans << '\n';
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