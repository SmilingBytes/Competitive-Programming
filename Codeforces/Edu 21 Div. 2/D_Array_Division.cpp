/**
 *    author:  ismail
 *    created: 11.02.2020  12:35:14
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
  int n;
  cin >> n;
  vector<int> a(n + 2, 0);
  ll sm = 0LL, s = 0LL;
  for (int i = 0; i < n; i++) cin >> a[i], sm += a[i];

  unordered_map<ll, int> mp, mp2;
  mp[a[0]]++;
  for (int i = 1; i < n; i++) mp2[a[i]]++;

  if (sm % 2 == 1) return cout << "NO\n", 0;
  sm /= 2;
  for (int i = 0; i < n; i++) {
    s += a[i];
    if (s == sm) return cout << "YES\n", 0;
    if (s > sm) {
      ll x = s - sm;
      if (mp[x] > 0) return cout << "YES\n", 0;
    } else {
      ll x = sm - s;
      if (mp2[x] > 0) return cout << "YES\n", 0;
    }
    mp[a[i + 1]]++;
    mp2[a[i + 1]]--;
  }
  return cout << "NO\n", 0;
}