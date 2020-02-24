#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  int a[n], ans[n];
  bool flag = true;
  for (register int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < i + 1) flag = false;
  }
  if (flag) {
    int mn = 1;
    bool f[n + 1];
    memset(f, false, sizeof(f));
    for (register int i = 0; i < n; i++) {
      if (!f[a[i]]) {
        ans[i] = a[i];
        f[a[i]] = true;
        if (mn == a[i])
          while (f[mn]) mn++;

      } else {
        ans[i] = mn;
        f[mn] = true;
        while (f[mn]) mn++;
      }
    }
    for (const auto val : ans) cout << val << " ";
  } else
    cout << -1;
  cout << "\n";
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