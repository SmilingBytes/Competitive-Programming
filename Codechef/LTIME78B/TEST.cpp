#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      v.push_back(x);
    }

    sort(v.begin(), v.end());
    int c = 0, i;
    v.push_back(-1);
    for (i = 0; i < n - 1; ++i) {
      if (i > 0)
        while (i < n and (v[i] - v[i - 1]) == 1) i++;

      if ((v[i + 1] - v[i]) == 1)
        ++i;
      else if ((v[i + 1] - v[i]) == 2) {
        ++c;
        ++i;
      } else if (i < n) {
        ++c;
      }
    }
    if (i == n - 1)
      if (v[i] - v[i - 1] != 1) c++;

    cout << c << endl;
  }

  return 0;
}