#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n;
  cin >> n;
  priority_queue<int> a, b;
  for (register int i = 1, x, y, d; i < n; i++) {
    cin >> x >> y >> d;
    b.push(d);
  }
  for (register int i = 0, d; i < n; i++) {
    cin >> d;
    a.push(d);
  }
  int cnt = 0;
  if (b.top() > a.top()) {
    cnt += 2;
    b.pop();
  } else {
    a.pop();
  }

  while (!b.empty()) {
    if (b.top() > a.top())
      cnt++;
    else
      a.pop();
    b.pop();
  }
  cout << cnt << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  register int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}