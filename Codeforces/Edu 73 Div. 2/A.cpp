#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
const int mod = 1e9 + 7;

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n;
    unordered_map<ll, ll> umap;
    ll tmp;
    for (auto i = 0; i < n; i++) {
      cin >> tmp;
      umap[tmp]++;
    }
    if (umap.find(2048) != umap.end()) {
      cout << "YES"
           << "\n";
      continue;
    }
    vector<ll> need;
    ll x = 1024;
    ll m = 2;
    bool flag = false;
    while (x > 0) {
      auto got = umap.find(x);
      if (got == umap.end()) {
        m *= 2;
      } else {
        if (got->second >= m) {
          flag = true;
          break;
        } else {
          m -= got->second;
          m *= 2;
        }
      }
      x = x / 2;
      // std::cout << got->first << " is " << got->second;
    }
    if (flag)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}