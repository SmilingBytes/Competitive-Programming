/**
 *    author:  ismail
 *    created: 09.02.2020  20:48:54
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

int f(int a, int b) {
  int x = a | b;
  return x - b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0, d; i < n; i++) {
    cin >> d;
    mp[d]++;
  }
  // int ans = a[0];
  // for (int i = 1; i < n; i++) {
  //   ans = f(ans, a[i]);
  // }
  // cout << ans << "\n";

  return 0;
}