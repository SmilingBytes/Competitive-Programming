// check python code
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

int a[100000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (auto i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int mx = a[k - 1];
    int nn = 0, r = 0, i = 0;
    for (i = 0; i < k; i++)
      if (a[i] == mx) r++;
    while (a[i] == mx) {
      nn++;
      i++;
    }
    nn += r;
    cout << "N = " << nn << " R = " << r << "\n";
  }
  return 0;
}