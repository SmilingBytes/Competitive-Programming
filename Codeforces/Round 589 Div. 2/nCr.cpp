#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int main() {
  ll f[70] = {0};
  f[0] = 1;
  for (auto i = 1; i <= 69; i++) {
    f[i] = (f[i - 1] * i) % mod;
  }

  ll ans = f[69] / (f[1] * f[68]);
  cout << ans << "\n";
  return 0;
}