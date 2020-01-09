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

int value[100000000];
vector<int> twos;

int solve(int x, int p) {
  if (x < 0) return INF;
  if (x == 0) return 0;
  if (x < 100000000)
    if (value[x] != -1) return value[x];
  int best = INF;
  for (int c : twos) {
    best = min(best, solve(x - c + p, p) + 1);
  }
  if (x < 100000000) value[x] = best;
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  ll n, k, p;
  cin >> n >> p;
  if (n <= p) return cout << -1 << "\n", 0;
  k = log2l(n - p);
  int m = 1;
  twos.push_back(m);
  for (auto i = 0; i <= k; i++) {
    m *= 2;
    twos.push_back(m);
  }
  int ans = solve(n, p);
  cout << ans << "\n";

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}