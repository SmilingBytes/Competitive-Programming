/**
 *    author:  ismail
 *    created: 29.06.2020  11:19:39
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<ll, int>> like, alice, bob, dlike;
  for (int i = 0, t, a, b; i < n; i++) {
    cin >> t >> a >> b;
    if (a and b) {
      like.push_back(make_pair(t, i + 1));
    } else if (a) {
      alice.push_back(make_pair(t, i + 1));
    } else if (b) {
      bob.push_back(make_pair(t, i + 1));
    } else {
      dlike.push_back(make_pair(t, i + 1));
    }
  }

  int ml = (int)min(alice.size(), bob.size());
  if (k > like.size() + ml) {
    cout << -1 << "\n";
    return;
  }

  sort(like.begin(), like.end());
  sort(alice.begin(), alice.end());
  sort(bob.begin(), bob.end());
  sort(dlike.begin(), dlike.end());

  set<ll> ans;

  ll time = 0ll, d = 0ll;
  int cnt = 0, ab = 0, a = 0;
  int lv = k;
  while (lv--) {
    if (a < ml) {
      d = alice[a].first + bob[a].first;
      if (ab >= like.size()) {
        ans.insert(alice[a].second);
        ans.insert(bob[a].second);
        time += d, a++, cnt += 2;
      } else if (d <= like[ab].first) {
        ans.insert(alice[a].second);
        ans.insert(bob[a].second);
        time += d, a++, cnt += 2;
      } else if (ab < like.size()) {
        ans.insert(like[ab].second);
        time += like[ab].first, ab++, cnt++;
      }
    } else if (ab < like.size()) {
      ans.insert(like[ab].second);
      time += like[ab].first, ab++, cnt++;
    }
  }
  ll diff = 0, x = 0;

  int al = k, bl = k, b = a;

  if (cnt < m) {
    set<pair<ll, int>> s;
    while (ab < like.size()) {
      s.insert(like[ab]);
      ab++;
    }
    while (a < alice.size()) {
      s.insert(alice[a]);
      a++;
    }
    while (b < bob.size()) {
      s.insert(bob[b]);
      b++;
    }
    while (x < dlike.size()) {
      s.insert(dlike[x]);
      x++;
    }

    auto it = s.begin();

    while (cnt < m) {
      ans.insert((*it).second);
      time += (*it).first;
      cnt++, it++;
    }
  }
  a--;
  if (cnt > m) {
    while (ab < like.size() and cnt > m) {
      ans.insert(like[ab].second);
      time += like[ab].first, ab++;
      ans.erase(alice[a].second);
      ans.erase(bob[a].second);
      time -= (alice[a].first + bob[a].first), a--, cnt--;
    }
    if (cnt != m) {
      cout << -1 << "\n";
      return;
    }
  }

  cout << time << "\n";
  for (const auto val : ans) cout << val << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}