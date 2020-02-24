#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(a) a.size()

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  unordered_map<ll, ll, custom_hash> mp;
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
  while (!a.empty()) {
    cout << a.front() << " ";
    a.pop_front();
  }
  return 0;
}