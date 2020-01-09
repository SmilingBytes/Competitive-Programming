#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define w(a) cerr << #a << " : " << (a) << "\n";

void solve() {
  int n = 1 << 3;  // 2 multiply
  int k = 3;
  int len = 4;
  int res = (float(k) / float(len)) + .9;
  // cout << res << "\n";
  string s = "01110", a;
  a = s;
  for (register int i = 0; i < s.size(); i++) {
    int x = s[i] - '0';
    char ch = (1 - x) + '0';
    cout << ch << "\n";

    a[i] = (1 - (s[i] - '0')) + '0';
  }

  cout << a << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  // mp.max_load_factor(0.25);mp.reserve(512);
  solve();
  return 0;
}