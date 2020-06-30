/**
 *    author:  ismail
 *    created: 23.06.2020  20:23:07
 **/
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string st;
  int n;
  cin >> n >> st;
  char s[n];
  for (int i = 0; i < n; i++) s[i] = st[i];

  int i = n - 1;
  while (i >= 0 and s[i] == '1') i--;

  while (i >= 0) {
    if (s[i] == '1') {
      int d = i + 2;
      while (d < n and (s[d] == '0' or s[d] == 'd')) s[d] = 'd', d++;
      while (i >= 0 and (s[i] == '1' or s[i] == 'd')) s[i] = 'd', i--;
    }
    i--;
  }
  for (int i = 0; i < n; i++)
    if (s[i] != 'd') cout << s[i];
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--) solve();

  return 0;
}