#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FAST                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

typedef long long li;
const int mod = 1e9 + 7;

template <class T> void read(T &x) {
  int f = 0;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-')
      f = 1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x = f ? -x : x;
}

void solve() {
  freopen("input.txt", "r", stdin);
  int n;
  read(n);
  int cnt1 = 0, cnt2 = 0;
  for (size_t i = 0; i < n; i++) {
    int tmp;
    read(tmp);
    if (tmp % 2 == 0)
      cnt1++;
    else
      cnt2++;
  }
  int ans = (cnt1 > cnt2) ? cnt2 : cnt1;
  printf("%d\n", ans);
}

signed main() {
  FAST;
  solve();
  return 0;
}
