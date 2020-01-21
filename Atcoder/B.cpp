/**
 *    author:  ismail
 *    created: 20.01.2020  21:51:57
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
  int n, m;
  cin >> n >> m;
  if (n > m) {
    for (int i = 0; i < n; i++) cout << m;
  } else {
    for (int i = 0; i < m; i++) cout << n;
  }
  return cout << "\n", 0;
}