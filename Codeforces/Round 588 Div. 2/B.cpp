#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
const int mod = 1e9 + 7;

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (n == 1 and k > 0) {
    s.replace(0, 1, "0");
  } else if (k > 0) {
    s.replace(0, 1, "1");
    ll nn = n - 1, kk = k - 1, i = 1;
    while (nn > 0 and kk > 0) {
      s.replace(i, 1, "0");
      i++;
    }
  }
  cout << s << "\n";

  return 0;
}