#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimization("O3")
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int mod = 1e9 + 7;
#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

ll binpower(ll base, ll e, ll mod) {
  ll result = 1;
  base %= mod;
  while (e) {
    if (e & 1) result = (ull)result * base % mod;
    base = (ull)base * base % mod;
    e >>= 1;
  }
  return result;
}

bool check_composite(ull n, ll a, ll d, int s) {
  ll x = binpower(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (int r = 1; r < s; r++) {
    x = (ull)x * x % n;
    if (x == n - 1) return false;
  }
  return true;
}

bool MillerRabin(ull n) {  // returns true if n is prime, else returns false.
  if (n < 2) return false;

  ll r = 0;
  ull d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (check_composite(n, a, d, r)) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  unsigned long long n = 10000000000000000001;
  if (MillerRabin(n)) {
    cout << "Msg"
         << "\n";

  } else {
    cout << "no"
         << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif

  return 0;
}