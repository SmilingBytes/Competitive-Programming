/**
 *    author:  ismail
 *    created: 31.05.2020  20:36:13
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n, x, odd = 0, even = 0;
  cin >> n >> x;
  for (int i = 0, d; i < n; i++) {
    cin >> d;
    if (d & 1)
      odd++;
    else
      even++;
  }
  if (odd == 0) return cout << "No\n", 0;
  if (odd % 2 == 0) odd--;

  if (x & 1) {
    if (odd >= x) return cout << "Yes\n", 0;
    int rem = x - odd;
    if (rem <= even) return cout << "Yes\n", 0;
  } else {
    if (even % 2 == 0) even--;
    if (even >= x) return cout << "Yes\n", 0;
    if (even < 1) return cout << "No\n", 0;
    int rem = x - even;
    if (rem <= odd) return cout << "Yes\n", 0;
  }
  cout << "No\n";
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}