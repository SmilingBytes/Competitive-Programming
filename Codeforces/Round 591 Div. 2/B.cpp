#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimization("O3")
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
  while (t--) {
    string s, t;
    cin >> s >> t;
    set<char> ss(begin(s), end(s));
    set<char> tt(begin(t), end(t));
    ll n = tt.size();
    bool flag = false;
    for (auto d : ss) {
      for (auto i = 0; i < n; i++) {
        if (d == t[i]) {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    (flag) ? cout << "YES"
                  << "\n"
           : cout << "NO"
                  << "\n";
  }

#ifndef ONLINE_JUDGE
  std::cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}