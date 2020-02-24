/**
 *    author:  ismail
 *    created: 19.01.2020  19:35:06
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, s, k;
    cin >> n >> s >> k;
    unordered_set<int> f;
    for (int i = 1, d; i <= k; i++) {
      cin >> d;
      f.insert(d);
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      if ((s + i <= n and f.find(s + i) == f.end()) or
          (s - i >= 1 and f.find(s - i) == f.end())) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}