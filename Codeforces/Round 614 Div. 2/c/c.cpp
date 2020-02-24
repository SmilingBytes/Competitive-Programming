/**
 *    author:  ismail
 *    created: 19.01.2020  21:00:27
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
  int n, q;
  cin >> n >> q;
  vector<bool> a(n, true);
  vector<bool> b(n, true);
  bool f = true;
  int p = 1, ab = 1;
  int x, y;
  set<int> blk;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    (x == 1) ? a[y] = !a[y] : b[y] = !b[y];
    if (x == 1) {
      if (b[y] == false or b[y + 1] == false) {
        if (y >= p) blk.insert(y);
      } else if (blk.find(y) != blk.end()) {
        blk.erase(y);
      }
    } else if (x == 2) {
      if (a[y] == false or a[y + 1] == false) {
        if (y >= p) blk.insert(y);
      } else if (blk.find(y) != blk.end()) {
                blk.erase(y);
      }
    }
    if (blk.empty()) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}