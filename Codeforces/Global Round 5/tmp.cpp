#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  int n, k;
  cin >> n;
  int a[n];
  bool f[n];
  memset(f, false, sizeof(f));
  register int j = 0;
  int ans = 0, b;
  for (register int i = 0; i < n; i++) cin >> a[i];
  for (register int i = 0; i < n; i++) {
    cin >> b;
    while (f[a[j]] and j < n) j++;
    if (a[j] == b)
      j++;
    else {
      f[b] = true;
      ans++;
    }
  }
  std::cout << ans << "\n";
  return 0;
}