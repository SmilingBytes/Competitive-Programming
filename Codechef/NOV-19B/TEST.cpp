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
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  vector<int> v(2, 1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  int len = 34;

  string s = "111";
  // string p = s  len;
  char ch = 'a', c = 'z';
  int d = c - 96;
  cout << d << "\n";
  double ans = 10000001.0;
  if (ans > 1e7) {
    cout << "Infinity"
         << "\n";
  }

  // cout << s << "\n";

  return 0;
}