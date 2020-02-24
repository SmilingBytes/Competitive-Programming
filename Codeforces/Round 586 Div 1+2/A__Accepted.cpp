#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
const int mod = 1e9 + 7;

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int one = 0, zero = 0;
  for (char& c : s) {
    if (c == 'n') one++;
    if (c == 'z') zero++;
  }
  if (n < 3)
    cout << 0 << "\n";
  else {
    for (int i = 0; i < one; i++) cout << 1 << " ";
    for (int i = 0; i < zero; i++) cout << 0 << " ";
  }
  cout << "\n";

  return 0;
}