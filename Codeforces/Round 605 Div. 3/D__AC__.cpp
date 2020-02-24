#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";
const int N = 2e5 + 10;
int n;
int a[N], l[N], r[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) l[i] = (a[i] > a[i - 1] ? l[i - 1] + 1 : 1);
  for (int i = n; i >= 1; i--) r[i] = (a[i] < a[i + 1] ? r[i + 1] + 1 : 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, max(l[i], r[i]));
  for (int i = 2; i < n; i++)
    if (a[i - 1] < a[i + 1]) ans = max(ans, l[i - 1] + r[i + 1]);

  return cout << ans, 0;
}