#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n, g = 1, s = 0, b = 0, tmp = 0;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  register int i = 1;
  while (i < n and a[i] == a[i - 1]) i++;
  g = i;
  s = g + 1;
  i = i + g + 1;
  while (i < n and a[i] == a[i - 1]) {
    s++;
    i++;
  }
  b = g + 1;
  i = i + b;
  while (i < n and a[i] == a[i - 1]) {
    b++;
    i++;
  }
  int mx = g + s + b;
  if (mx > n / 2) return cout << "0 0 0\n", 0;
  mx = (n / 2) - mx;
  while (mx > 0 and i < n) {
    tmp = 0;
    while (i < n and a[i] == a[i - 1]) {
      tmp++;
      i++;
    }
    mx -= tmp;
    if (mx >= 0) b += tmp;
  }

  return cout << g << " " << s << " " << b << '\n', 0;
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