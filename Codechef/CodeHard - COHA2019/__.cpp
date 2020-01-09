#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define int int64_t
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FAST                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
typedef long long li;
const int mod = 1e9 + 7;

template <class T> void read(T &n) {
  static char c;
  while ((c = getchar_unlocked()) && c <= ' ')
    ;
  n = c - '0';
  while ((c = getchar_unlocked()) && c > ' ')
    n = (n << 3) + (n << 1) + c - '0';
}

signed main() {
  FAST;
  register int n, k, t;
  read(n);
  read(k);
  register size_t ans = 0;
  while (n--) {
    read(t);
    ans += !(t % k);
  }
  printf("%d\n", ans);
  return 0;
}
