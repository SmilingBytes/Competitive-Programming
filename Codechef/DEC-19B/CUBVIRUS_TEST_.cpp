#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define ff first
#define ss second
#define w(a) std::cerr << #a << " : " << (a) << "\n";

pair<int, int> a[4][101];
int n;

int findFirst(set<int> v) {  // code
  int mx = 0;
  for (register int i = n; i > 0; i--) {
    if (sz(v) == 3) {
      int n1 = a[1][i].first, n2 = a[2][i].first, n3 = a[3][i].first;
      mx = (n1 > n2 and n1 > n3) ? 1 : 0;
      if (mx == 0) (n2 > n1 and n2 > n3) ? 2 : 0;
      if (mx == 0) (n3 > n2 and n3 > n1) ? 3 : 0;
      if (mx == 0) {
        if (n1 < n2 and n1 < n3) v.erase(1);
        if (n2 < n1 and n2 < n3) v.erase(2);
        if (n3 < n1 and n3 < n2) v.erase(3);
      } else {
        return mx;
      }
    } else if (sz(v) == 2) {
      auto it = v.begin();
      int d1 = *it;
      it++;
      int n1 = a[d1][i].first, n2 = a[*it][i].first;
      if (n1 > n2) return d1;
      if (n2 > n1) return *it;
    } else if (sz(v) == 1) {
      auto it = v.begin();
      return *it;
    }
  }
  return 0;
}

void solve() {
  cin >> n;
  int ans[4][n + 1];
  memset(ans, -1, sizeof(ans));
  string str[10001];
  int x[101], y[101], z[101], cnt = 0;

  for (register int i = 1, yi, zi; i <= n * n; i++) {
    cin >> str[i];
    yi = i % 3;
    if (yi == 0) yi = n;
    zi = ((i - yi) / n) + 1;
    for (register int j = 0; j < n; j++) {
      if (str[i][j] == '1') {
        x[j + 1]++;
        y[yi]++;
        z[zi]++;
      }
    }
  }

  for (register int i = 1; i <= n; i++) {
    a[1][i] = make_pair(x[i], i);
    a[2][i] = make_pair(y[i], i);
    a[3][i] = make_pair(z[i], i);
  }
  sort(a[1] + 1, a[1] + n + 1);
  sort(a[2] + 1, a[2] + n + 1);
  sort(a[3] + 1, a[3] + n + 1);

  set<int> v = {1, 3};
  int fst = findFirst(v);
  if (fst == 0) fst = 1;
  for (register int i = 1; i <= n; i++) ans[fst][i] = a[fst][i].second;

  v.erase(fst);
  auto it = v.begin();
  int sec = *it;
  if (sec == 0) sec = 3;
  for (register int i = 1; i <= n; i++) ans[sec][i] = a[sec][i].second;

  int lst = 2;
  bitset<105> f;
  stack<vector<int>> stk;
  vector<int> setA;
  for (register int i = 1; i <= n; i++) setA.push_back(i);

  for (register int i = 1; i <= n; i++) {
    vector<int> setB, setn;
    int ax = ans[1][i] - 1, az = ans[3][1];
    int k = (az - 1) * n + 1, l = 1;
    while (k <= az * n) {
      if (str[k][ax] == '0') {
        setB.push_back(l);
      }
      l++;
      k++;
    }
    std::set_intersection(all(setA), all(setB),
                          std::inserter(setn, setn.begin()));
    if (sz(setn) == 0) break;
    setA = setn;
    stk.push(setn);
  }
  int i = 1;
  while (!stk.empty()) {
    int ax = ans[1][i];
    auto stc = stk.top();
    stk.pop();
    for (register int j = 0; j < sz(stc); j++) {
      int d = stc[j];
      if (!f[d]) {
        ans[lst][i] = d;
        f.set(d);
        break;
      }
    }
    i++;
  }
  int l = 1;
  while (i <= n) {
    while (ans[lst][i] == -1) {
      if (f[l]) {
        l++;
      } else {
        ans[lst][i] = l;
        f.set(l);
      }
    }
    i++;
  }

  l = 1;
  for (register int i = 1; i <= n; i++) {
    while (ans[2][i] == -1) {
      if (!f[l]) ans[2][i] = l;
      l++;
    }
  }
  for (register int i = 1; i <= 3; i++) {
    for (register int j = 1; j <= n; j++) cout << ans[i][j] << " ";
    cout << "\n";
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