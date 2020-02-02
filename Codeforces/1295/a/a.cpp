/**
 *    author:  ismail
 *    created: 29.01.2020  20:35:13
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
    ll n;
    cin >> n;
    ll res = n / 2;
    if (n % 2 == 0) {
      for (int i = 0; i < res; i++) cout << 1;
    } else {
      cout << 7;
      for (int i = 1; i < res; i++) cout << 1;
    }
    cout << "\n";
  }
  return 0;
}