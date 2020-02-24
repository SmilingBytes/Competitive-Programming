#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  string s;
  cin >> s;
  if (sz(s) == 1) return cout << 0 << "\n", 0;

  int up = 0, down = 0, left = 0, right = 0;
  for (const auto ch : s) {
    if (ch == 'U')
      up++;
    else if (ch == 'D')
      down++;
    else if (ch == 'L')
      left++;
    else if (ch == 'R')
      right++;
  }
  int up_down = min(up, down);
  int left_right = min(left, right);
  ll ans = up_down * 2 + left_right * 2;
  if (up_down + left_right == 0) return cout << 0 << "\n", 0;
  if (up_down == 0) return cout << 2 << "\nLR\n", 0;
  if (left_right == 0) return cout << 2 << "\nUD\n", 0;
  cout << ans << '\n';
  for (register int i = 0; i < up_down; i++) cout << 'U';
  for (register int i = 0; i < left_right; i++) cout << 'L';
  for (register int i = 0; i < up_down; i++) cout << 'D';
  for (register int i = 0; i < left_right; i++) cout << 'R';
  return 0;
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