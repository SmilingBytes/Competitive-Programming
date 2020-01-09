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
  freopen("out.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    unordered_map<int, int, chash> mp;
    int c[32], a[n + 1];
    memset(c, 0, sizeof(c));
    int odd = 0, ans = 0;
    for (auto i = 1; i <= n; i++) {
      cin >> a[i];
      (c[a[i]] & 1) ? odd-- : odd++;
      c[a[i]]++;
      mp[odd] = i;
      cout << odd << " ";
    }
    cout << "\n";

    for (const auto val : a) cout << val << " ";
    ans = max(ans, (mp[1] - 1) / 2);
    cout << "\n";

    for (const auto val : mp) cout << val.ff << "\t" << val.ss << "\n";
    cout << "\n";

    odd = 0;
    memset(c, 0, sizeof(c));
    for (auto i = 2; i <= n - 2; i++) {
      (c[a[i - 1]] & 1) ? odd-- : odd++;
      c[a[i - 1]]++;
      int x = 1;
      x += odd;
      ans = max(ans, (mp[x] - i) / 2);
      cout << i << " =>\t" << x << " ans = \t" << ans << "\n";
    }
    // cout << ans << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}