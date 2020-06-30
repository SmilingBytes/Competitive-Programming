/**
 *    author:  ismail
 *    created: 07.06.2020  22:16:48
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  unordered_map<int, int> mp;
  for (int i = 0, d; i < n; i++) {
    cin >> d;
    a[d] = i;
  }
  for (int i = 0, d, k; i < n; i++) {
    cin >> d;
    k = (a[d] - i + n) % n;
    mp[k]++;
  }
  int ans = 0;
  for (auto x : mp) ans = max(x.second, ans);
  cout << ans << "\n";
  return 0;
}