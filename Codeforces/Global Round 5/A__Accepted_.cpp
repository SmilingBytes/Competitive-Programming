#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

using namespace std;

typedef long long ll;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  int b = 0;
  while (t--) {
    int a;
    cin >> a;
    if (a == 0) {
      cout << 0 << "\n";
    } else if (a % 2 == 0) {
      cout << a / 2 << "\n";
    } else {
      if (a > 0) {
        if (b == 0 or b == -1) {
          cout << a / 2 << "\n";
          b++;
        } else if (b == 1) {
          cout << (a / 2) + 1 << "\n";
          b--;
        }
      } else {
        if (b == 0 or b == 1) {
          cout << a / 2 << "\n";
          b--;
        } else if (b == -1) {
          cout << (a / 2) - 1 << "\n";
          b++;
        }
      }
    }
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}