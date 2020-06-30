/**
 *    author:  ismail
 *    created: 09.05.2020  22:21:11
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int a = 0, b = 0, aa = 0, bb = 0, m = 0, n;
  cin >> n;
  deque<int> dq;
  for (int i = 0, d; i < n; i++) {
    cin >> d;
    dq.push_back(d);
  }

  bool f = true;
  while (!dq.empty()) {
    if (f) {  // alice
      aa += dq.front();
      dq.pop_front();
      if (aa > bb) {
        a += aa;
        f = false;
        bb = 0;
        m++;
      }
    } else {  // bob
      bb += dq.back();
      dq.pop_back();
      if (bb > aa) {
        b += bb;
        f = true;
        aa = 0;
        m++;
      }
    }
  }

  if (f and aa > 0) {  // alice
    a += aa;
    m++;
  } else if (!f and bb > 0) {  // bob
    b += bb;
    m++;
  }
  cout << m << " " << a << " " << b << '\n';
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}