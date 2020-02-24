// https://codeforces.com/contest/1287/problem/C
/**
 *    author:  ismail
 *    created: 05.01.2020  22:03:12
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  int cnt = 0, ans = 0;
  set<int> odd, even;
  for (int i = 1; i <= n; i += 2) odd.insert(i);
  for (int i = 2; i <= n; i += 2) even.insert(i);

  vector<int> a(n + 2);
  a[0] = a[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (odd.find(a[i]) != odd.end())
      odd.erase(a[i]);
    else if (even.find(a[i]) != even.end()) {
      cnt++;
      even.erase(a[i]);
    }
  }
  vector<pair<int, int>> one, two;
  int f = 0;
  int o = 0, e = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      o++;
      e++;
    } else if (a[i] & 1) {
      if (f == 1) {
        if (o > 0) one.push_back(make_pair(o, i - 1));
      } else
        f = 1;
      o = 0;
    } else {
      if (f == 2) {
        if (e > 0) two.push_back(make_pair(e, i - 1));
      } else
        f = 2;
      e = 0;
    }
  }

  sort(all(one));
  sort(all(two));
  int m = sz(one);
  auto it = odd.begin();
  while (!odd.empty() and m > 0) {
    m--;
    int pos = one[m].second;
    a[pos] = *it;
    odd.erase(a[pos]);
  }
  it = even.begin();
  m = sz(two);
  while (!even.empty() and m > 0) {
    m--;
    int pos = two[m].second;
    a[pos] = *it;
    even.erase(a[pos]);
  }

  int j = 1;
  while (j <= n and a[j] == 0) j++;
  j--;
  int k = 0;
  while (k <= n and a[n - k] == 0) k++;
  if (j > 0 and j < k) {
    if (a[j + 1] & 1) {
      if (!odd.empty()) {
        it = odd.begin();
        while (!odd.empty() and j > 0) {
          a[j] = *it;
          odd.erase(*it);
          j--;
        }
      }
    } else {
      if (!even.empty()) {
        it = even.begin();
        while (!even.empty() and j > 0) {
          a[j] = *it;
          even.erase(*it);
          j--;
        }
      }
    }
  } else if (k > 0) {
    if (a[n - k] & 1) {
      if (!odd.empty()) {
        it = odd.begin();
        while (!odd.empty() and k > 0) {
          a[n - (k - 1)] = *it;
          odd.erase(*it);
          k--;
        }
      }
    } else {
      if (!even.empty()) {
        it = even.begin();
        while (!even.empty() and k > 0) {
          a[n - (k - 1)] = *it;
          even.erase(*it);
          k--;
        }
      }
    }
  }
  it = odd.begin();
  auto ie = even.begin();
  for (int i = 2; i < n; i++) {
    if (a[i] == 0) {
      if (a[i - 1] & 1) {
        if (!odd.empty()) {
          a[i] = *it;
          odd.erase(*it);
        } else {
          a[i] = *ie;
          even.erase(*ie);
        }
      } else {
        if (!even.empty()) {
          a[i] = *ie;
          even.erase(*ie);
        } else {
          a[i] = *it;
          odd.erase(*it);
        }
      }
    }
    if ((a[i] & 1) and !(a[i - 1] & 1)) ans++;
    if ((a[i] & 1) and !(a[i + 1] & 1)) ans++;
  }
  for (const auto val : a) std::cout << val << " ";
  std::cout << "\n";

  std::cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  solve();
  return 0;
}