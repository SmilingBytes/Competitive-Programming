/**
 *    author:  ismail
 *    created: 29.06.2020  11:19:39
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> like, alice, bob;
  for (int i = 0, t, a, b; i < n; i++) {
    cin >> t >> a >> b;
    if (a == 1 and b == 1) {
      like.push_back(t);
    } else if (a == 1 and b == 0) {
      alice.push_back(t);
    } else if (a == 0 and b == 1) {
      bob.push_back(t);
    }
  }
  if (k > like.size() + min(alice.size(), bob.size())) {
    cout << -1 << "\n";
    return;
  }

  sort(like.begin(), like.end());
  sort(alice.begin(), alice.end());
  sort(bob.begin(), bob.end());

  int ml = (int)min(alice.size(), bob.size());
  int j = k - ml;
  if (j < 0) j = 0;

  ll time = 0ll;
  int i = j, cnt = j, ab = 0;
  while (j--) time += like[j];

  while (cnt < k) {
    if (ab < ml and i < like.size()) {
      if (like[i] <= alice[ab] + bob[ab]) {
        time += like[i];
        i++, cnt++;
      } else {
        time += alice[ab] + bob[ab];
        ab++, cnt++;
      }
    } else if (ab >= ml) {
      time += like[i], cnt++, i++;
    } else if (i >= like.size()) {
      time += alice[ab] + bob[ab], ab++, cnt++;
    }
  }
  cout << time << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}