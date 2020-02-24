#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

int n, k;
string s, t;
void solve() {
  cin >> n >> k;
  cin >> s;
  t = s;
  for (int i = 0; i < k; ++i) t[i] = s[i];
  for (int i = k; i < n; ++i) t[i] = t[i - k];
  if (t >= s) {
    cout << n << '\n' << t;
  } else {
    for (int i = k - 1; i >= 0; --i) {
      if (s[i] != '9') {
        for (int j = i; j < n; j += k) t[j]++;
        break;
      } else {
        for (int j = i; j < n; j += k) t[j] = '0';
      }
    }
    cout << n << '\n' << t;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  solve();
  return 0;
}