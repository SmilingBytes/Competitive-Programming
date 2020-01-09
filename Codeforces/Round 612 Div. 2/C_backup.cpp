// https://codeforces.com/contest/1287/problem/C
/**
 *    author:  ismail
 *    created: 05.01.2020  20:45:44
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  int cnt = 0, ans = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      ans++;
      continue;
    }
    if ((a[i] & 1)) cnt++;
  }
  bool f;
  int i = 0;
  while (i < n and a[i] == 0) i++;
  f = (a[i] & 1) ? true : false;
  bool foo = f;
  i++;
  vector<pair<int, int>> odd, even;
  int o = 0, e = 0;
  for (; i < n; i++) {
    if (a[i] == 0) {
      (f) ? o++ : e++;
      continue;
    }
    if (a[i] & 1) {
      if (f) {
        if (o >= 1) {
          int pos = i - o;
          odd.push_back(make_pair(o, pos));
        }
      }
    } else {
      if (!f) {
        if (e >= 1) {
          int pos = i - e;
          even.push_back(make_pair(e, pos));
        }
      }
    }
    e = 0;
    o = 0;
    f = (a[i] & 1) ? true : false;
  }

  int re = n / 2;
  int ro = n - re;
  ro -= cnt;
  re = ans - ro;
  sort(all(odd));
  sort(all(even));

  int m = sz(odd);
  int j = 0;
  while (m > 0 and ro > 0) {
    int p = odd[j++].second;
    while (1) {
      if (a[p] != 0) break;
      a[p] = 1;
      ro--;
      p++;
    }
    m--;
  }

  m = sz(even);
  j = 0;
  while (m > 0 and ro > 0) {
    int p = even[j++].second;
    while (1) {
      if (a[p] != 0) break;
      a[p] = 2;
      re--;
      p++;
    }
    m--;
  }

  i = 0;
  ans = 0;
  while (i < n and a[i] == 0) {
    i++;
    if (foo) {
      if (ro > 0)
        a[i] = 3;
      else {
        ans++;
        re--;
        a[i] = 6;
        break;
      }
    } else {
      if (re > 0)
        a[i] = 4;
      else {
        ans++;
        a[i] = 5;
        ro--;
        break;
      }
    }
  }
  for (; i < n; i++) {
    if (a[i] == 0) {
      if (a[i - 1] & 1) {
        if (ro > 0) {
          ro--;
          a[i] = 3;
        } else {
          ans++;
          a[i] = 6;
          re--;
        }
      } else {
        if (re > 0) {
          re--;
          a[i] = 4;
        } else {
          ans++;
          a[i] = 5;
          ro--;
        }
      }
    } else if (a[i] & 1 and !(a[i - 1] & 1)) {
      ans++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}