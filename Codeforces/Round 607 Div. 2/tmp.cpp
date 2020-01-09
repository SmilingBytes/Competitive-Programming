#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

std::string operator*(const std::string& s, size_t n) {
  std::string result;
  result.reserve(s.size() * n);
  for (size_t i = 0; i < n; ++i) {
    result += s;
  }
  return result;
}
void solve() {
  int n;
  int l = 1;
  string s = "3234567", c;
  n = sz(s);
  c = s.substr(l, n - l);
  cout << c << '\n';
  s = s.substr(0, l);
  cout << s << "\n";
  int i = s[l - 1] - '1' + 1;
  cout << i << "\n";
  string a = "222", b;
  // b = 3 * a;
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