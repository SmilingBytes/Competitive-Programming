// https://codeforces.com/contest/1270/problem/D
/**
 *    author:  ismail
 *    created: 29.12.2019  22:06:18
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, k;
  set<int> s;
  vector<int> a(k + 1);
  for (int i = 1; i <= k + 1; i++) {
    cout << "?";
    if (i + k <= n)
      for (int j = 1; j <= k + 1; j++) {
        if (j == i) continue;
        cout << " " << j;
      }
    cout << endl;

    int pos, apos;
    cin >> pos >> apos;
    a[pos] = apos;
  }
  // cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}