/**
 *    author:  ismail
 *    created: 23.06.2020  21:35:30
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  ll n, k;
  cin >> n >> k;

  ll a[n], w[k], sum = 0ll;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < k; i++) cin >> w[i];

  sort(a, a + n);
  sort(w, w + k);

  int d = 1;
  while (d <= k) sum += a[n - d], d++;

  int m = 1, j = 0;
  while (j < k and w[j] == 1) sum += a[n - m], m++, j++;

  int pos = n - k;
  while (j < k) pos = pos - w[j] + 1, sum += a[pos], j++;

  cout << sum << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}