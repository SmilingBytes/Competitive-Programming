// https://codeforces.com/contest/1283/problem/C
/**
 *    author:  ismail
 *    created: 28.12.2019  23:26:21
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
  vector<int> a(n);
  std::set<int> s;
  for (int i = 1; i <= n; ++i) s.insert(s.end(), i);
  for (int i = 0, d; i < n; i++) {
    cin >> d;
    a[i] = d;
    if (d != 0) s.erase(d);
  }
  auto it = s.rbegin();
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if (*it == i + 1) {
        it++;
        int dl = *it;
        it--;
        s.erase(dl);
        cout << dl << " ";
      } else {
        cout << *it << " ";
        it++;
      }
    } else {
      cout << a[i] << " ";
    }
  }

  // cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in1.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  solve();
  return 0;
}