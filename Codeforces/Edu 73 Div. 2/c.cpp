#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, c, m, o;
  cin >> n;
  while (n--) {
    cin >> c >> m >> o;
    cout << min(min(c, m), (c + m + o) / 3) << endl;
  }
  return 0;
}