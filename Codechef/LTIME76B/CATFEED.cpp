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
    ll n, m;
    cin >> n >> m;
    ll a[m] = {0};
    unordered_map<ll, ll> mp;
    bool flag = true;
    ll cnt = 0, mx = 1, tmp;
    ll i = 0, j = 1;
    while (i < m) {
      while (i < j * n and i < m) {
        cin >> tmp;
        mp[tmp]++;
        if (mp[tmp] > j) flag = false;
        i++;
      }
      j++;
    }
    if (flag)
      cout << "YES"
           << "\n";
    else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}