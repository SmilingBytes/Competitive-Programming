#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  std::cin >> t;
  while (t--) {
    int n, k, a[n];
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
      std::cin >> a[i];

    bool flag = true;
    if (n == 1)
      a[0] = (a[0] == -1) ? 1 : a[0];
    if (k == 1 and n > 1)
      flag = false;
    else {
      for (int i = 0; i < n; ++i) {
        bool chk = false;
        if (a[i] == -1 and 0 < i < n - 1) {
          for (int d = 1; d <= k; ++d)
            if (a[i - 1] != d and a[i + 1] != d) {
              a[i] = d;
              chk = true;
              break;
            }
          if (chk != true) {
            flag = false;
            break;
          }
        } else if (a[i] == -1 and i == 0)
          a[i] = (a[i + 1] != 1) ? 1 : 2;
        else if (a[i] == -1 and i == n - 1)
          a[i] = (a[i - 1] != 1) ? 1 : 2;
      }
    }
    if (flag == true) {
      std::cout << "YES" << '\n';
      for (int i = 0; i < n; ++i)
        std::cout << a[i] << ' ';
      std::cout << '\n';
    } else
      std::cout << "NO" << '\n';
  }
  return 0;
}
