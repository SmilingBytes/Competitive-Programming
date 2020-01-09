#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> x[2];
  int a[n], b[n + 1] = {0};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
    if (a[i] == 0) x[0].push_back(i + 1);
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0) {
      x[1].push_back(i);
    }
  }
  // cout<<x[0].size()<<" "<<x[1].size()<<endl;
  int j = 0, k = 0;
  j = x[0].size() - 1;
  for (int i = 0; i < x[0].size() - 1; i++) {
    if (x[0][i] == x[1][i]) {
      k = x[1][j];
      x[1][j] = x[1][i];
      x[1][i] = k;
    }
  }
  if (x[0][j] == x[1][j]) {
    k = x[1][0];
    x[1][0] = x[1][j];
    x[1][j] = k;
  }
  j = 0;
  k = x[0].size();
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      a[i] = x[1][j];
      j++;
    }
    cout << a[i] << " ";
  }
}