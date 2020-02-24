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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("input.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    register std::bitset<10> a, b;
    register int n;
    cin >> n;
    cin >> a;

    while (n > 1) {
      cin >> b;
      a ^= b;
      n--;
    }
    cout << a.count() << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}