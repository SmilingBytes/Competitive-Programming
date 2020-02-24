#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
#define INF 1000000000

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

ull power(int x, int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;  // y = y/2
    x = x * x;
  }
  return res;
}

string convert(int n, int b) {
  string s;
  int i = 0;
  while (n > 0) {
    int rem = n % b;
    n = n / b;
    char ch = (rem > 9) ? rem + '7' : rem + '0';
    s.push_back(ch);
  }
  reverse(all(s));
  return s;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    bool flag = true;
    vector<pair<int, string> > list;
    map<string, int> mp;
    int n, num = -1, b;
    cin >> n;

    for (auto i = 0; i < n; i++) {
      string s;
      cin >> b >> s;
      if (flag) {
        if (b != -1) {
          int len = sz(s), tmp = 0;
          for (const auto d : s) {
            int dd = (d > '9') ? (d - '7') : (d - '0');
            tmp += dd * power(b, --len);
          }
          mp[s] = b;

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

    if (num > (int)1e12) flag = false;

    if (num != -1 and flag) {
      int b = 2;
      while (b <= 36) {
        mp[convert(num, b)] = b;
        b++;
      }
    }
    if (flag) {
      for (const auto x : list) {
        if (mp[x.ss] == 0) {
          flag = false;
          break;
        }
      }
    }
    (flag) ? cout << num << "\n" : cout << -1 << "\n";
  }
#ifndef ONLINE_JUDGE
  std::cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}