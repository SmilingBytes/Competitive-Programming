#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T, a[6];
  cin >> T;
  while (T--) {
    for (auto i = 0; i < 6; ++i)
      cin >> a[i];
    vector<pair<int, int>> vect;
    for (auto i = 0; i < 3; i++)
      vect.push_back(make_pair(a[i], a[i + 3]));
    sort(vect.begin(), vect.end());
    bool flag = true;
    for (auto i = 0; i < 2 && flag; i++) {
      if ((vect[i].first == vect[i + 1].first) &&
          (vect[i].second != vect[i + 1].second))
        flag = false;
      else if (vect[i].second > vect[i + 1].second)
        flag = false;
    }
    (flag) ? cout << "FAIR" << '\n' : cout << "NOT FAIR" << '\n';
  }
  return 0;
}
