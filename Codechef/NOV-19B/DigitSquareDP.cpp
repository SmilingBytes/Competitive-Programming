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

int base[] = {4, 9, 16, 25, 36, 49, 64, 81};
unordered_map<int, int, chash> mp;
unordered_map<int, bool, chash> dup;
int sq[9001];
// string dp[1000001];
vector<string> dp(1000001, "-1");
int n;

void preCaclSquare() {
  for (register int i = 1; i <= 9000; ++i) {
    register int s = i * i;
    mp[s]++;
    sq[i] = s;
  }
}

int value[81000000];
int first[81000000];

int solve(int x, int dgt) {
  if (dgt == 0) return -1;
  if (mp[x]) return 0;
  int best = INF;
  for (auto c : base) {
    dgt--;
    int nn = x - 1 + c;
    best = min(best, solve(nn, dgt) + 1);
  }
  value[x] = best;
  return best;
}

void digitDP() {
  value[0] = 0;
  for (register int x = 1; x <= 81000000; x++) {
    value[x] = INF;
    for (int c : base) {
      if (x - c >= 0 && value[x - c] + 1 < value[x]) {
        value[x] = value[x - c] + 1;
        first[x] = c;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  memset(value, INF, sizeof(value));
  preCaclSquare();
  value[0] = 0;
  digitDP();

  // solve(29000);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    auto lwb = lower_bound(sq, sq + 9001, n);
    auto upb = lower_bound(sq, sq + 9001, (n * 81));
    int upi = (upb - (sq + 1));
    int lwi = (lwb - (sq + 0));
    int ans = 1e9;
    for (register int i = lwi; i < upi; i++) {
      int nn = sq[i] - n + 1;
      ans = min(ans, solve(nn, n));
    }
    // cout << ans << "\n";
  }
  for (register int i = 1; i < 1000; i++) {
    cout << value[i] << "\n";
  }
  // cout << "\n";
#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}