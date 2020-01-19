/**
 *    author:  ismail
 *    created: 19.01.2020  04:07:59
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
  ll n;
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0, ln; i < n; i++) {
    cin >> ln;
    int mx = 0, mn = 1e9;
    for (int j = 0, d; j < ln; j++) {
      cin >> d;
      if (d > mx) mx = d;
      if (d < mn) mn = d;
    }
    a[i] = make_pair(mn, mx);
  }
  ll cnt = 0;
  for (int i = 0, mn, mx; i < n; i++) {
    mn = a[i].first;
    mx = a[i].second;
    if (mn < mx) cnt++;
    for (int j = i + 1, x; j < n; j++) {
      // i+j
      x = a[j].second;
      if (x > mn) cnt++;
      // j+i
      x = a[j].first;
      if (x < mx) cnt++;
    }
  }
  cout << cnt << "\n";

  return 0;
}