#pragma GCC optimization("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n;
  cin >> n;
  int a[n];
  for (int &x : a) cin >> x;
  bool l = false, r = false;
  for (int &x : a) {
    int num;
    cin >> num;
    x = num - x;
  }
  for (register int i = 0, dif = 0; i < n; i++) {
    if (a[i] != 0) {
      if (!l) {
        l = true;
        dif = a[i];
        if (dif < 0) return cout << "NO\n", 0;
      } else if (r or a[i] != dif or a[i] < 0)
        return cout << "NO\n", 0;
    } else if (l and !r)
      r = true;
  }

  return cout << "YES\n", 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  register int tc;
  cin >> tc;
  while (tc--) solve();

#ifndef ONLINE_JUDGE
  std::cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}