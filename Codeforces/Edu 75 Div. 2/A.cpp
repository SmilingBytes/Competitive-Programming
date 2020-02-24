#include <bits/stdc++.h>

using namespace std;

bool ans[26];

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    memset(ans, false, sizeof ans);

    int i = 0;
    while (i < s.size()) {
      int j = i;
      while (j + 1 < s.size() && s[j + 1] == s[i]) j++;
      if ((j - i) % 2 == 0) ans[s[i] - 'a'] = true;
      i = j;
      i++;
    }
    for (int i = 0; i < 26; i++)
      if (ans[i]) cout << char('a' + i);
    cout << "\n";
  }
  return 0;
}