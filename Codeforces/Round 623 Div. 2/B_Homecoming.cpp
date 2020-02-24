/**
 *    author:  ismail
 *    created: 24.02.2020  20:36:19
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int a, b, p;
  cin >> a >> b >> p;
  string s;
  cin >> s;
  int n = s.size();
  char ch = s[n - 2];
  int pay = (ch == 'A' ? a : b);

  if (pay > p) return cout << n << "\n", 0;
  int pos = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == ch) continue;
    ch = s[i];
    pay += (ch == 'A' ? a : b);
    if (pay > p) {
      pos = i + 2;
      break;
    }
  }

  cout << pos << '\n';
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}