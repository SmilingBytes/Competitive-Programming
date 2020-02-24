#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  string s, c;
  cin >> s >> c;
  int n = min(sz(s), sz(c));
  priority_queue<int> a[27];
  multiset<char> st;
  for (register int i = 0; i < sz(s); i++) {
    a[s[i] - 'A'].push(i);
    st.insert(s[i]);
  }
  auto it = st.begin();
  for (register int i = 0; i < n; i++) {
    if (s[i] < c[i]) return cout << s << "\n", 0;
    if (s[i] >= c[i]) {
      if (*it > c[i]) return cout << "---\n", 0;
      if (*it < c[i]) {
        auto pq = a[*it - 'A'];
        int p = pq.top();
        char ch = s[i];
        s[i] = s[p];
        s[p] = ch;
        return cout << s << "\n", 0;
      }
      if (*it == c[i]) {
        it++;
      }
    }
    if (s[i] > c[i]) return cout << "---\n", 0;
  }
  int mn = min(sz(s), sz(c)) - 1;
  if (s[mn] == c[mn] and sz(s) < sz(c)) return cout << s << "\n", 0;

  return cout << "---\n", 0;
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