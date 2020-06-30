/**
 *    author:  ismail
 *    created: 28.06.2020  14:28:29
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  ll n, k;
  cin >> n >> k;
  if (k >= n) {
    cout << 1 << "\n";
    return;
  }

  vector<int> v;
  int lim = sqrt(n);
  for (int i = 1; i <= lim; i++) {
    if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
  }
  sort(v.begin(), v.end());
  int i = v.size();
  while (i--) {
    if (v[i] <= k) {
      cout << n / v[i] << "\n";
      return;
    }
  }

  cout << n << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}