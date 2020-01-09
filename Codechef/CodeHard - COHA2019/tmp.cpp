#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // FAST;
  //    freopen("input.txt", "r", stdin);
  // solve();
  // test();
  // bool p[9];
  std::vector<int> p[9];

  memset(p, 9, sizeof(p));
  std::cout << p[5] << '\n';
  for (size_t i = 0; i < 9; i++) {
    std::cout << p[i] << " \n"[i == 8];
  }
  std::cout << "end" << '\n';
  return 0;
}
