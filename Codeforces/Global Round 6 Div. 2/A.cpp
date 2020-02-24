#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool check(string s) {
  int n = sz(s);
  bool f = false;
  ll digitSum = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != '0' and (s[i] - '0') % 2 == 0) f = true;
    digitSum += (s[i] - '0');
  }
  if (digitSum == 0) return true;
  return (f and (digitSum % 3 == 0));
}

void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  ll sum = 0;
  bool f1 = false;

  for (auto ch : s) {
    if (ch == '0') {
      f1 = true;
      break;
    }
  }
  if (f1) {
    bool flag = check(s);
    cout << (flag ? "red\n" : "cyan\n");
  } else {
    cout << "cyan\n";
  }
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