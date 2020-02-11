/**
 *    author:  ismail
 *    created: 09.02.2020  16:52:12
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
  int n, a, b, k, ans = 0;
  cin >> n >> a >> b >> k;
  int skp = b / a;
  if (b % a != 0) skp++;
  vector<int> vec;
  for (int i = 0, d; i < n; i++) {
    cin >> d;
    ll num = 0ll + a + b;
    int rem = d % num;
    if (rem == 0)
      vec.push_back(skp);
    else if (rem <= a) {
      ans++;
    } else {
      rem -= a;
      int skp = rem / a;
      if (rem % a != 0) skp++;
      vec.push_back(skp);
    }
  }
  sort(all(vec));
  int i = 0;
  while (i < sz(vec)) {
    if (vec[i] > k) break;
    k -= vec[i];
    ans++;
    i++;
  }
  cout << ans << "\n";

  return 0;
}