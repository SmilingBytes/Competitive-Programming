#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  register int n;
  cin >> n;
  vector<int> ans;
  ans.push_back(0);
  for (register int i = 1, r; i <= n / 2; i = r + 1) {
    r = n / (n / i);
    ans.push_back(r);
  }
  ans.push_back(n);
  cout << sz(ans) << "\n";
  for (const auto x : ans) cout << x << " ";
  std::cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}