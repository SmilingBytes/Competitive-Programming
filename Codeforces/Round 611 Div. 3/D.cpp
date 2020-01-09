// https://codeforces.com/contest/1283/problem/D
/**
 *    author:  ismail
 *    created: 28.12.2019  23:59:39
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

const ll lim = 2e9;
void solve() {
  int n, m;
  ll cnt = 0, res = 0;
  cin >> n >> m;
  unordered_set<ll> occupied;
  set<ll> tree;
  vector<ll> a(m);
  for (int i = 0, d; i < n; i++) {
    cin >> d;
    tree.insert(d);
    occupied.insert(d);
  }

  auto it = tree.begin();
  ll dif = 1, mid = 0, lst = 0;
  while (cnt < m) {
    if (it == tree.end()) {
      dif++;
      it = tree.begin();
    }
    ll d = *it;
    it++;
    if (it != tree.end()) mid = *it;
    it++;
    if (it != tree.end()) lst = *it;
    it--;
    if (mid - dif - dif <= d and mid + dif + dif >= lst) {
      it++;
      tree.erase(mid);
    }

    ll d1 = d + dif, d2 = d - dif;
    if (d1 <= lim and d1 >= -2e9 and occupied.find(d1) == occupied.end()) {
      a[cnt] = d1;
      res += dif;
      occupied.insert(d1);
      cnt++;
    }
    if (d2 <= lim and d2 >= -2e9 and occupied.find(d2) == occupied.end()) {
      a[cnt] = d2;
      res += dif;
      occupied.insert(d2);
      cnt++;
    }
  }

  cout << res << '\n';
  for (int i = 0; i < m; i++) {
    cout << a[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  solve();
  return 0;
}