#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

#define ll long long
#define int int64_t

const int mod = 1e9 + 7;

// Function that returns the N-th digit
char NthDigit(int n) {
  string s = "";
  int c = 1;
  for (int i = 1;; i++) {
    if (c < 10)
      s += char(48 + c);
    else {
      string s1 = "";
      int dup = c;
      while (dup) {
        s1 += char((dup % 10) + 48);
        dup /= 10;
      }
      reverse(s1.begin(), s1.end());
      s += s1;
    }
    c++;
    if (s.length() >= n) {
      return s[n - 1];
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  ll n, ans = 0;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    std::cin >> n;
    char ch = NthDigit(n);
    int num = ch - '0';
    ll d = static_cast<long long>(num);
    ans += d;
  }
  std::cout << ans << '\n';
  return 0;
}
