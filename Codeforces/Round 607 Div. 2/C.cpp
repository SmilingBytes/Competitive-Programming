#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

ll n = 0;

std::string operator*(const std::string &ss, size_t n) {
  std::string result;
  result.reserve(ss.size() * n);
  for (size_t i = 0; i < n; ++i) {
    result += ss;
  }
  return result;
}

const ll mod = 1e9 + 7;
string s, c;
char ch;

ll algo(ll &l) {
  l++;
  int times = ch - '1' + 1;
  ch = c[0];
  c = (std::string(c) * times);
  ll len = sz(c);
  c = c.substr(1, len - 1);
  return (times * len) + l;
}

bool solve() {
  int x;
  cin >> x >> s;
  ll l = 0;
  ll ans = 0;
  if (x == l) return std::cout << sz(s) << "\n", 0;
  c = s.substr(1, n - 1);
  ch = s[0];
  while (l != x) {
    ans = algo(l);
  }
  ans %= mod;
  return std::cout << ans << "\n", 0;
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