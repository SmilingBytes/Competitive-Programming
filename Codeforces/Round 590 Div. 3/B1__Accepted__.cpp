#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  map<ll, ll> mp;
  deque<ll> a;
  ll n, k, d, m = 0;
  cin >> n >> k;

  for (auto i = 0; i < n; i++) {
    cin >> d;
    if (!mp[d]) {
      mp[d] = 1;
      a.emplace_front(d);
      if (sz(a) > k) {
        mp[a.back()] = 0;
        a.pop_back();
      }
    }
  }
  cout << sz(a) << "\n";
  for (const auto val : a) cout << val << " ";
  return 0;
}