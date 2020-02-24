#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    unordered_map<int, int, chash> mp;
    for (register int i = 1; i <= n; i++) {
      cin >> a[i];
      mp[a[i]] = i;
    }
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }

    int i = 1, v = 1;
    while (i <= n and v < n) {
      int p = mp[v] - 1;
      cout << v << " ";
      a[mp[v]] = -1;
      v++;
      while (p < i and v < n) {
        p = mp[v] - 1;
        v++;
      }
      while (i < p) {
        if (a[i] != -1) cout << a[i] << " ";
        i++;
      }
    }
    cout << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}