#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

using namespace std;

typedef long long ll;
#define MAXN 1000001

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()

bool isPrime[MAXN];
mll mp;

void findPrimes() {
  memset(isPrime, true, sizeof(isPrime));
  for (register int i = 4; i < MAXN; i += 2) isPrime[i] = false;
  register int np = 3;
  while (np * np <= MAXN) {
    for (register int i = np * 2; i < MAXN; i += np) isPrime[i] = false;
    np += 2;
    while (np < MAXN and isPrime[np] == false) np += 2;
  }
}

void factor(register int d) {
  if (d % 2 == 1) {
    for (register int j = 3; j * j <= d; j += 2)
      if (d % j == 0) {
        mp[j]++;
        if (d / j != j) mp[d / j]++;
      }
  } else {
    for (register int j = 2; j * j <= d; j++)
      if (d % j == 0) {
        mp[j]++;
        if (d / j != j) mp[d / j]++;
      }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  findPrimes();
  int t;
  cin >> t;
  while (t--) {
    mp.clear();
    ll n, ans = 0;
    cin >> n;

    if (n > 100) {
      for (register int i = 0; i < n; i++) {
        register int d;
        cin >> d;
        if (d == 1)
          mp[1] = i;
        else if (isPrime[d] == false)
          factor(d);
        ans = max(ans, mp[d]);
        mp[d]++;
      }
      std::cout << ans << "\n";
    } else {
      int a[n];
      register int ans = 0;
      cin >> a[0];
      for (register int i = 1; i < n; i++) {
        cin >> a[i];
        register int d = 0;
        for (register int j = i - 1; j >= 0; j--) {
          if (a[j] % a[i] == 0) d++;
        }
        ans = max(ans, d);
      }
      cout << ans << "\n";
    }
  }
#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}