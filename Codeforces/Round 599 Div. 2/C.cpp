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

set<long long> trial_division2(long long n) {
  set<long long> factorization;
  while (n % 2 == 0) {
    factorization.insert(2);
    n /= 2;
  }
  for (long long d = 3; d * d <= n; d += 2) {
    while (n % d == 0) {
      factorization.insert(d);
      n /= d;
    }
  }
  if (n > 1) factorization.insert(n);
  return factorization;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  ll n;
  cin >> n;
  set<ll> pf;
  pf = trial_division2(n);

  if (n < 3) return cout << n << "\n", 0;
  ll ans = 1e12;
  if (n > 1000000) {
    ll n1 = n / 2;
    ll n2 = n - n1;
    string s1(n1, '1');
    string s2(n2, '1');
  } else {
    string s(n, '1');
    for (auto d : pf) {
      while (d <= n) {
        d += d;
      }
    }
  }
  cout << ans << "\n";

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}