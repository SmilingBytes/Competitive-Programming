#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline int read() {
  int n = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = n * 10 + ch - '0';
    ch = getchar();
  }
  return n * f;
}

void solve() {
  int n = read();
  ll ans = 0, x = 0, y = 0;
  for (register int i = 0, d; i < n; i++) {
    d = read();
    ans += (d >> 1);
    if (d % 2 == 1) (i % 2 == 0) ? x++ : y++;
  }
  ans += min(x, y);
  printf("%lld", ans);
}

int main() {
  solve();
  return 0;
}