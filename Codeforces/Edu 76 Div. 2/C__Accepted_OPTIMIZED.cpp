#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

struct chash {
  const int RANDOM =
      (long long)(make_unique<char>().get()) ^
      chrono::high_resolution_clock::now().time_since_epoch().count();
  static unsigned long long hash_f(unsigned long long x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
  int operator()(int x) const { return hash_f(x) ^ RANDOM; }
};

int read() {
  int sss = 0, fff = 1;
  char ccc;
  ccc = getc();
  while (ccc < '0' || ccc > '9') {
    if (ccc == '-') fff = -1;
    ccc = getc();
  }
  while (ccc >= '0' && ccc <= '9')
    sss = (sss << 1) + (sss << 3) + (ccc ^ '0'), ccc = getc();
  return sss * fff;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t = read();
  while (t--) {
    int n, num, ans = INF;
    n = read();
    gp_hash_table<int, int, chash> mp;

    for (register int i = 1; i <= n; i++) {
      num = read();
      if (mp[num] != 0) ans = min(ans, (abs(i - mp[num]) + 1));
      mp[num] = i;
    }
    cout << (ans == INF ? -1 : ans) << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}