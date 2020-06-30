/**
 *    author:  ismail
 *    created: 28.06.2020  21:13:43
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  string s;
  cin >> n >> s;
  int ob = 0, cb = 0, ans = 0;
  for (auto ch : s) {
    (ch == '(') ? ob++ : cb++;
    if (cb > ob) ans = max((cb - ob), ans);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}