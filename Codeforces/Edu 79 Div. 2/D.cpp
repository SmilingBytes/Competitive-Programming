// https://codeforces.com/contest/1279/problem/D
/**
 *    author:  Smile.Forever
 *    created: 27.12.2019  23:32:15
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

const ll mod = 998244353;
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

ll gcdExtended(ll a, ll b, ll *x, ll *y);

ll modInverse(ll b) {
  ll x, y;  // used in extended GCD algorithm
  ll g = gcdExtended(b, mod, &x, &y);
  if (g != 1) return -1;
  return (x % mod + mod) % mod;
}

ll modDivide(ll a, ll b) {
  a = a % mod;
  ll inv = modInverse(b);
  ll res = (inv * a) % mod;
  return res;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  ll x1, y1;
  ll gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}

void solve() {
  ll n, ans = 0LL;
  cin >> n;
  int a[n];
  vector<ll> v[n];
  unordered_map<int, ll, chash> mp;
  mp.max_load_factor(0.25);
  mp.reserve(500);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0, d; j < a[i]; j++) {
      cin >> d;
      v[i].push_back(d);
      mp[d]++;
    }
  }
  ll x = 0LL, y = 0LL;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i]; j++) {
      ll d = v[i][j];
      y = (y + (n - mp[d])) % mod;
      x = (x + mp[d]) % mod;
    }
  }
  ans = modDivide(x, y);
  ans %= mod;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}