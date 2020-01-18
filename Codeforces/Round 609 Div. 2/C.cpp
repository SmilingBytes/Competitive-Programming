#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

void solve() {
  int n, k;
  string s, S;
  cin >> n >> k >> s;
  S = s.substr(0, k);
  for (register int i = k; i < n - k; i += k) S.append(S.substr(0, k));
  for (register int i = sz(S); i < n; i++) S.push_back(S[i - k]);

  if (S >= s) {
    cout << n << "\n" << S << "\n";
  } else {
    for (register int i = k - 1; i >= 0; i--) {
      if (S[i] == '9') {
        for (register int j = i; j < n; j += k) S[j] = '0';
      } else {
        for (register int j = i; j < n; j += k) S[j] = ++S[j];
        break;
      }
    }
    cout << n << "\n" << S;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif

  solve();
  return 0;
}