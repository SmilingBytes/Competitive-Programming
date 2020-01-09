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

ll gcd(ll a, ll b);

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  ll mx = 0;
  ll a[n];

  for (auto i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > mx) mx = a[i];
  }

  ll s = 0, z = 0;
  for (auto i = 0; i < n; i++) {
    a[i] = mx - a[i];
    s += a[i];
    z = gcd(a[i], z);
  }

  ll y = s / z;
  cout << y << " " << z << "\n";

  return 0;
}

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}