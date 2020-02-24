#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  bitset<27> a;
  char ch;
  for (register int i = 0; i < k; i++) {
    cin >> ch;
    a.set(ch - 'a');
  }
  ll cnt = 0, ans = 0;
  for (const auto ch : s) {
    if (a[ch - 'a']) {
      cnt++;
    } else {
      ans += ((cnt * (cnt + 1)) / 2);
      cnt = 0;
    }
  }
  ans += ((cnt * (cnt + 1)) / 2);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  solve();
  return 0;
}