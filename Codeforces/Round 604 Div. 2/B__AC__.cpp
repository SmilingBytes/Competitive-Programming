#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n;
  cin >> n;
  int a[n + 1];
  for (register int i = 1, num; i <= n; i++) {
    cin >> num;
    a[num] = i;
  }
  if (n == 1) return cout << "1\n", 0;

  cout << '1';
  int l = a[1], r = a[1];
  for (register int i = 2; i < n; i++) {
    l = min(l, a[i]);
    r = max(r, a[i]);
    cout << (((r - l) >= i) ? '0' : '1');
  }
  return cout << "1\n", 0;
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