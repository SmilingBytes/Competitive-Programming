#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  string a = "11001", b = "111";
  int n = sz(a);
  const int N = 1024;  // maximum string size
  bitset<N> x(a), y(b), z = x ^ y;
  string c = (z.to_string()).substr(N - n, n);
  // c = c.substr(N - n, n);
  cout << c << "\n";

  // cout << ans << '\n';
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