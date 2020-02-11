/**
 *    author:  ismail
 *    created: 11.02.2020  14:08:16
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, w;
  cin >> n >> w;
  vector<pair<int, int>> a(n, {0, 0});
  vector<int> ans(n, 0);
  ll sm = 0LL;
  for (int i = 0, d; i < n; i++) {
    cin >> d;
    a[i] = {d, i};
    ans[i] = (d / 2) + (d % 2);
    sm += ans[i];
  }
  if (sm > w) return cout << -1, 0;

  sort(all(a));
  ll rem = w - sm;
  int i = n - 1;
  while (i >= 0 and rem > 0) {
    int pos = a[i].second;
    int val = a[i].first;
    auto d = val - ans[pos];
    if (d >= rem) {
      ans[pos] += (int)rem;
      break;
    } else {
      ans[pos] = val;
      rem -= d;
    }
    i--;
  }
  for (auto x : ans) cout << x << " ";
  cout << "\n";

  return 0;
}