/**
 *    author:  ismail
 *    created: 29.01.2020  21:46:28
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
  int n = 5;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    a.push_back(i + 1);
  }
  auto lb = lower_bound(a.begin(), a.end(), 6);
  cout << *lb << "\n";

  return 0;
}