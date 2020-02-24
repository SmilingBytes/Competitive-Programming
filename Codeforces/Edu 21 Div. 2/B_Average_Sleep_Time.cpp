/**
 *    author:  ismail
 *    created: 11.02.2020  13:10:35
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll sm = 0LL, total = 0LL;
  for (int i = 0; i < k; i++) sm += a[i];

  total = sm;
  for (int i = k, j = 0; i < n; i++, j++) {
    sm = sm + a[i] - a[j];
    total += sm;
  }

  cout << fixed << setprecision(10) << (double)total / (n - k + 1) << "\n";
  return 0;
}