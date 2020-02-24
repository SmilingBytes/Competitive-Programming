#include <bits/stdc++.h>
#define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int q;
int a[N], u[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out_ac.txt", "w", stdout);
#endif
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    int p = 1;
    while (p <= n) {
      int mn = p;
      for (int j = p; j <= n; ++j) {
        if (a[mn] > a[j]) {
          mn = j;
        }
      }
      if (mn == p) {
        ++p;
        continue;
      }
      for (int j = mn; j > p; --j) {
        swap(a[j], a[j - 1]);
      }
      p = mn;
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", a[i]);
    }
    printf("\n");
  }
  return 0;
}