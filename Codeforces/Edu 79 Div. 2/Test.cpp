#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d ", &t);
  int i;
  for (i = 0; i < t; i++) {
    char c[1];
    scanf("%c ", &c[0]);
    if (c[0] == 'B' || c[0] == 'b') {
      printf("Battleship\n");
    } else if (c[0] == 'C' || c[0] == 'c') {
      printf("Cruiser\n");
    } else if (c[0] == 'D' || c[0] == 'd') {
      printf("Destroyer\n");
    } else if (c[0] == 'F' || c[0] == 'f') {
      printf("Frigate\n");
    }
  }
  return 0;
}