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

inline ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

inline ll findGCD(ll arr[], ll n) {
  ll result = arr[0];
  for (auto i = 1; i < n; i++) result = gcd(arr[i], result);
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ll n, k;
  cin >> n;
  ll m[n][n];
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < n; j++) {
      ll tmp;
      cin >> m[i][j];
    }
  }
  ll a[n];
  a[0] = 0;
  for (auto i = 1; i < n; i++) {
    a[i] = findGCD(m[i], n);
  }
  a[0] = m[1][0] / a[1];
  for (const auto val : a) cout << val << " ";

  // ll g = findGCD(m, n);
  // for (auto i = 0; i < n; i++) {
  //   if (i == 1)
  //     cout << g << " ";
  //   else
  //     cout << m[i] / g << " ";
  // }
  // cout << "\n";

  return 0;
}