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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  ll n, k;
  cin >> n >> k;
  ll a[n];
  for (auto i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < 1 << 5; i++) {
    for (int j = 1; j <= 5; j++) {
      if ((1 << j) & i) {
        cout << a[j] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}