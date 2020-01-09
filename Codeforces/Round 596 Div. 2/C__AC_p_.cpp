#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  register int n, p;
  cin >> n >> p;
  if (n - p < 1) return cout << -1 << "\n", 0;
  for (register int i = 1; i < 32; i++)
    if (n - p * i >= i and __builtin_popcount(n - p * i) <= i)
      return cout << i << "\n", 0;
  cout << -1 << "\n";
  return 0;
}