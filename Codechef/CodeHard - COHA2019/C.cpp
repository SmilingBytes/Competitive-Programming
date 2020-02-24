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

#define int int64_t
#define ll long long
#define FAST                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

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

// Function that returns the N-th character
char NthCharacter(int n) {
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

    // if the length exceeds N
    if (s.length() >= n) {
      return s[n - 1];
    }
  }
}

signed main() {
  FAST;

  return 0;
}
