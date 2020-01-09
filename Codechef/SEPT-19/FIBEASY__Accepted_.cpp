#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int mod = 1e9 + 7;

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int f[60] = {0};
  f[0] = 0;
  f[1] = 1;
  for (int i = 2; i <= 60; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % 10;
  }

  int t;
  cin >> t;
  while (t--) {
    ull n;
    cin >> n;
    n = log2l(n);
    n = exp2l(n) - 1;
    cout << f[n % 60] << "\n";
  }
  return 0;
}