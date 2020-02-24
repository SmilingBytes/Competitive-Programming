#pragma GCC optimization("O3")
#pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int &x : a) cin >> x;
  bool f = true;
  int day = 1, st = 0;
  for (register int i = 0, num; i < n; i++) {
    if (a[i] + st >= k) {
      day++;
      st = (a[i] + st) - k;
    } else {
      f = false;
      break;
    }
  }
  if (f) {
    cout << "YES\n";
  } else {
    cout << "NO " << day << "\n";
  }
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