/**
 *    author:  ismail
 *    created: 09.05.2020  20:39:14
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n;
  cin >> n;
  if (n > 0 and n <= 9) return cout << 1 << "\n" << n << "\n", 0;

  vector<int> a;
  int i = 1, d = 0;

  int rem = n % 10;
  n /= 10;
  if (rem > 0) a.push_back(rem);

  while (n > 0) {
    rem = n % 10;
    n /= 10;
    i = i * 10;
    if (rem > 0) {
      d = rem * i;
      a.push_back(d);
    }
  }
  cout << a.size() << "\n";
  for (const auto val : a) std::cout << val << " ";
  std::cout << "\n";

  // cout << ans << '\n';
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