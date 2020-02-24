/**
 *    author:  ismail
 *    created: 12.02.2020  22:17:29
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  string s;
  cin >> s;
  int n = s.size();
  map<char, pair<char, char>> mp;
  deque<char> dq;
  set<char> alpha;
  for (char ch = 'a'; ch <= 'z'; ch++) alpha.insert(ch);

  if (n > 3) {
    mp[s[0]] = make_pair(s[1], '0');
    mp[s[1]] = make_pair(s[0], '0');
    dq.push_back(s[0]);
    dq.push_back(s[1]);
    alpha.erase(s[0]);
    alpha.erase(s[1]);

    for (int i = 1; i < n - 1; i++) {
      char ch = s[i], chk = s[i + 1];
      auto d = mp[ch];
      char a = d.first, b = d.second;

      if (chk == a or chk == b) continue;

      if (b == '0') {
        mp[ch] = make_pair(a, chk);
        if (mp.find(chk) == mp.end()) {
          mp[chk] = make_pair(ch, '0');

          if (alpha.find(chk) != alpha.end()) {
            if (dq.back() == ch)
              dq.push_back(chk);
            else if (dq.front() == ch)
              dq.push_front(chk);
            else {
              return cout << "NO\n", 0;
            }
            alpha.erase(chk);
          }

        } else {
          d = mp[chk];
          a = d.first, b = d.second;
          if (a == ch or b == ch) continue;
          if (b == '0') {
            mp[chk] = make_pair(a, ch);
          } else {
            return cout << "NO\n", 0;
          }
        }
      } else {
        return cout << "NO\n", 0;
      }
    }
  } else {
    cout << "YES\n";
    cout << s;
    for (auto ch : s) alpha.erase(ch);
    for (auto ch : alpha) cout << ch;
    return cout << "\n", 0;
  }

  bool f = false;
  for (auto m : mp) {
    auto d = m.second;
    char a = d.first, b = d.second;
    if (a == '0' or b == '0') {
      f = true;
      break;
    }
  }
  if (!f) return cout << "NO\n", 0;

  cout << "YES\n";
  for (int i = 0; i < dq.size(); i++) std::cout << dq[i];
  for (auto ch : alpha) cout << ch;
  return cout << '\n', 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}