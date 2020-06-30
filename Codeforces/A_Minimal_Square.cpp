/**
 *    author:  ismail
 *    created: 28.06.2020  13:58:43
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  int area = a * b * 2;
  a += a;
  if (a * a >= area)
    cout << a * a << "\n";
  else {
    cout << b * b << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}