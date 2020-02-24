#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void add(int &a, int &b) {
  register int cnt = 0;
  while (b > 0) {
    register int v = a & b;
    a = a ^ b;
    b = v << 1;
    cnt++;
  }
  cout << cnt << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  register int tc;
  cin >> tc;
  while (tc--) {
    string s1, s2;
    cin >> s1 >> s2;
    bitset<100000> a(s1), b(s2);
    if (b.none()) {
      cout << 0 << "\n";
      continue;
    } else if (a.none()) {
      cout << 1 << "\n";
      continue;
    }

    if (sz(s1) < 31 and sz(s2) < 31) {
      int a = stoi(s1, 0, 2);
      int b = stoi(s2, 0, 2);
      add(a, b);
      continue;
    }

    int na = sz(s1), nb = sz(s2);
    int ans = 0, cnt = 0;
    bool f = false;
    while (na > 0 and nb > 0) {
      na--;
      nb--;
      char ca = s1[na], cb = s2[nb];
      if (ca == '1' and cb == '1') {
        f = true;
        continue;
      }
      if (f and ca != cb) {
        cnt = 3;
        while (na > 0 and nb > 0 and s1[--na] != s2[--nb]) cnt++;
        if (na == 0) {
          while (nb > 0 and s2[--nb] == '1') cnt++;
        } else if (nb == 0) {
          while (na > 0 and s1[--na] == '1') cnt++;
        }
        ans = max(ans, cnt);
      }
      f = false;
    }
    if (ans <= 20) {
      const int m = 1e5 + 200;
      int cnt = 0;
      bitset<m> a(s1), b(s2);
      while (!b.none()) {
        bitset<m> v = a & b;
        a = a ^ b;
        b = v << 1;
        cnt++;
      }
      cout << cnt << "\n";
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}