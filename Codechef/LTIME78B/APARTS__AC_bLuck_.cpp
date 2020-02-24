#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

char ans[1001][1001];
int n, m;

void left(int i, int j) {
  while (i <= n and j > 0) {
    if (ans[i][j] == '2')
      ans[i][j] = '0';
    else
      break;
    i++;
    j--;
  }
}

void right(int i, int j) {
  while (i <= n and j <= m) {
    if (ans[i][j] == '2')
      ans[i][j] = '0';
    else
      break;
    i++;
    j++;
  }
}

void down(int i, int j) {
  while (i <= n) {
    if (ans[i][j] == '2') {
      ans[i][j] = '0';
      left(i + 1, j - 1);
      right(i + 1, j + 1);
    } else
      break;
    i++;
  }
}

void solve() {
  memset(ans, '2', sizeof ans);
  cin >> n >> m;
  int tot = n * m;
  pair<int, int> a[tot + 1];
  for (register int i = 1, w; i <= n; i++)
    for (register int j = 1; j <= m; j++) {
      cin >> w;
      a[w] = make_pair(i, j);
    }

  for (register int w = tot, i, j; w > 0; w--) {
    i = a[w].first;
    j = a[w].second;
    if (ans[i][j] == '2') {
      ans[i][j] = '1';
      left(i + 1, j - 1);
      right(i + 1, j + 1);
      down(i + 1, j);
    }
  }

  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= m; j++) cout << ans[i][j];
    cout << "\n";
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