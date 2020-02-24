#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

typedef long long ll;
typedef unsigned long long ull;
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

unordered_map<ull, int> mp;
ull sq[9001];
ll dp[1000001];
ll n;

void preCaclSquare() {
  for (register ll i = 2; i <= 9000; ++i) {
    register ull s = i * i;
    mp[s]++;
    sq[i] = s;
  }
}

void preSqr() {
  ll sum = 0;
  dp[1] = 1;
  register int i = 1, dc = 11;
  while (i <= 9) {
    ll d = (i * i) + 1 + sum;
    auto it = lower_bound(sq, sq + 9000, d);
    register int j = it - (sq + 0);
    register ll k = sq[j] - d + 2;
    while (j < 9000 and k < 1000000) {
      if (dp[k] == -1) dp[k] = j;
      j++;
      k = sq[j] - d + 2;
    }
    i++;
    dc++;
    if (dc % 10 == 0 and dc < 10000) {
      i = 1;
      dc += 2;
      int k = dc / 10;
      sum = 0;
      while (k > 0) {
        int d = k % 10;
        sum = sum + (d * d);
        k /= 10;
      }
    }
  }
}

bool digitDP(vector<int> &digit, int pos, ll sum) {
  if (pos < n) {
    ll minus = digit[pos - 1] * digit[pos - 1];
    sum = sum - minus;
    digit[pos - 1]++;
    if (digit[pos - 1] == 10) {
      if (pos == 1) return false;
      digit[pos - 1] = 1;
      digitDP(digit, pos - 1, sum);
    }
    ll dd = digit[pos - 1] * digit[pos - 1];
    ll d = dd + sum;
    digitDP(digit, pos + 1, d);
  }
  if (pos == n) {
    for (register int i = 1; i <= 9; i++) {
      ll dd = i * i;
      ll d = dd + sum;
      if (mp[d] == 1) {
        digit[pos - 1] = i;
        return true;
      }
    }
    digitDP(digit, pos - 1, sum);
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  preCaclSquare();
  memset(dp, -1, sizeof(dp));
  preSqr();

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    //   vector<int> digit(n, 1);
    //   digitDP(digit, n, n - 1);
    //   bool f = false;
    //   ll chk = 0;
    //   for (const auto d : digit) chk = chk + (d * d);
    //   if (mp[chk] == 1) f = true;
    //   if (f) {
    //     for (const auto val : digit) cout << val;
    //     cout << "\n";
    //   } else {
    //     cout << -1 << "\n";
    //   }
    // }

    // for (int i = 11000; i < 13000; i++) {
    //   cout << dp[i] << " ";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}