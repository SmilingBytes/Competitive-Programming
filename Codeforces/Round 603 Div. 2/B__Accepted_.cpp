#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  string s[n];
  unordered_map<string, ull> mp;
  for (register int i = 0; i < n; i++) {
    cin >> s[i];
    mp[s[i]]++;
  }

  ull cnt = 0;
  for (const auto x : mp) cnt += (x.second - 1);
  cout << cnt << "\n";

  for (register int i = 0; i < n; i++) {
    string pin = s[i];

    if (mp[pin] > 1) {
      mp[pin]--;
      for (char k = '0'; k <= '9'; k++) {
        pin[1] = k;
        if (mp[pin] == 0) {
          mp[pin]++;
          break;
        }
      }
      cout << pin << "\n";
    } else
      cout << pin << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}