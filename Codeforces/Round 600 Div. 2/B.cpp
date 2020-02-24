#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define ff first
#define ss second
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n;
  cin >> n;
  bool flag = true;
  vector<int> day;
  unordered_map<int, int> mp;
  unordered_map<int, int> prev;
  for (register int i = 0, cnt = 1, num; i < n; i++) {
    cin >> num;
    if (flag) {
      if (mp[abs(num)] == 0) {
        if (prev[abs(num)] == 0) {
          (num > 0) ? mp[num] = 1 : flag = false;
          prev[num] = 1;
        } else
          flag = false;
      } else {
        (num < 0) ? mp.erase(abs(num)) : flag = false;
      }
      if (sz(mp) == 0) {
        day.push_back(cnt);
        cnt = 0;
        prev.clear();
      }
    }
    cnt++;
  }
  if (sz(mp) != 0 or !flag) return cout << -1 << "\n", 0;
  cout << sz(day) << "\n";
  for (const auto val : day) cout << val << " ";
  cout << "\n";
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  solve();

#ifndef ONLINE_JUDGE
  std::cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}