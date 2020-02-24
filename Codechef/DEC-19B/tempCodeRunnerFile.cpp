#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, m, k;
  string s, b = " ";
  cin >> s >> m >> k;
  n = 1 << m;  // 2^m
  int p = (float(k) / float(n)) + .9;
  b[0] = s[p - 1];  // (strings are) zero based indexing
  for (int i = 1, sz; i <= m; i++) {
    string a;
    sz = b.size();
    for (auto ch : b) a.push_back((1 - (ch - '0')) + '0');
    b.append(a);
  }
  int pos = k - ((p - 1) * n);
  cout << b[pos - 1] << '\n';
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