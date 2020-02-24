#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

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

void solve() {
  int n, m = 1e9, ans = 0;
  cin >> n;
  int a[n + 2];
  for (register int i = 1; i <= n; i++) cin >> a[i];

  gp_hash_table<int, int, chash> mp;
  register int i = 1;
  while (i <= n) {
    while (i <= n and a[i] == a[i + 1]) i++;
    m = min(m, a[i]);
    mp[a[i]]++;
    i++;
  }
  for (const auto x : mp)
    if (x.first != m) ans += x.second;
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}