#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

using namespace std;

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

ull power(ull x, ull y) {
  ull res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;  // y = y/2
    x = x * x;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
    ull n, num = -1;
    int b;
    cin >> n;
    vector<pair<int, string> > list;
    bool mpc[37];
    memset(mpc, false, sizeof(mpc));
    map<string, ull> mp;

    bool flag = true;
    for (auto i = 0; i < n; i++) {
      string s;
      cin >> b >> s;
      if (flag) {
        if (b > 1) {
          ull ln = sz(s), tmp = 0;
          for (const auto d : s) {
            ull dd = (d > '9') ? d - '0' - 7 : d - '0';
            tmp += dd * power(b, --ln);
          }
          mp[s] = b;
          mpc[b] = true;

          if (num == -1) {
            num = tmp;
          } else if (num != tmp) {
            flag = false;
          }
        } else {
          list.push_back(make_pair(b, s));
        }
      }
    }

    if (flag) {
      for (const auto val : list) {
        string s = val.ss;
        if (mp[s] == 0) {
          bool chk = false;
          for (auto j = 2; j <= 36; j++) {
            if (mpc[j]) continue;
            ull ln = sz(s), tmp = 0;
            for (const auto d : s) {
              ull dd = (d > '9') ? d - '0' - 7 : d - '0';
              tmp += dd * power(j, --ln);
            }
            if (num == tmp) {
              chk = true;
              mp[s] = tmp;
              mpc[j] = true;
              break;
            }
          }
          if (!chk) {
            flag = false;
            break;
          }
        }
      }
    }
    if (flag)
      cout << num << "\n";
    else
      cout << -1 << "\n";
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif

  return 0;
}