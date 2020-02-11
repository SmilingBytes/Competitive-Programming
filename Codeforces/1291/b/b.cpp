// https://codeforces.com/contest/1291/problem/B
/**
 *    author:  ismail
 *    created: 02.02.2020  20:29:07
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
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0, d; i < n; i++) {
      cin >> d;
      a[i] = d;
    }
    int pos = 0, i = n - 1;
    while (pos < n and a[pos] >= pos) pos++;
    int c = 0;
    bool f = true;
    if (n > 1 and a[pos] == a[pos - 1]) a[pos]--;
    while (i >= pos) {
      if (a[i] >= c) {
        c++;
        i--;
      } else {
        f = false;
        break;
      }
    }
    if (f) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}