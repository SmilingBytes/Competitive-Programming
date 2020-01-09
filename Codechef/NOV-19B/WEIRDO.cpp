#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

unordered_set<char> v({'a', 'e', 'i', 'o', 'u'});

double pow(ll base, ll exp) {
  double result = 1.0;
  for (;;) {
    if (exp & 1) result *= base;
    exp >>= 1;
    if (!exp) break;
    base *= base;
  }
  return result;
}

bool createdBy(string &s) {
  ll n = sz(s);
  if (n == 2) {
    int cnt = v.count(s[0]) + v.count(s[1]);
    if (cnt == 0) return false;
  } else {
    for (register int i = 0; i <= n - 3; i++) {
      int cnt = v.count(s[i]) + v.count(s[i + 1]) + v.count(s[i + 2]);
      if (cnt < 2) return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(7);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    ll sn;
    cin >> sn;
    gp_hash_table<char, double> ax, afx, bx, bfx;
    double n = 0.0, m = 0.0;

    for (register int i = 0; i < sn; i++) {
      string s;
      cin >> s;

      if (createdBy(s)) {  // Alice
        bitset<32> b;
        n++;
        for (char ch : s) {
          afx[ch]++;
          if (b[ch - 96] == 0) {
            ax[ch]++;
            b[ch - 96] = 1;
          }
        }
      } else {  // Bob
        bitset<27> b;
        m++;
        for (char ch : s) {
          bfx[ch]++;
          if (b[ch - 96] == 0) {
            bx[ch]++;
            b[ch - 96] = 1;
          }
        }
      }
    }

    double sca = 1.0, scb = 1.0;
    for (auto d : ax) sca = sca * (d.ss / pow(afx[d.ff], n));
    for (auto d : bx) scb = scb * (d.ss / pow(bfx[d.ff], m));
    double ans = sca / scb;
    (ans > 1e7) ? cout << "Infinity"
                       << "\n"
                : cout << fixed << ans << "\n";
  }
  return 0;
}
