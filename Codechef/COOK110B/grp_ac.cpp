#include <assert.h>
#include <iostream>
using namespace std;

int T;
int A, B, C;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out_ac.txt", "w", stdout);
#endif
  cin >> T;
  assert(1 <= T && T <= 1000);
  while (T--) {
    cin >> A >> B >> C;
    cout << A << " " << B << " " << C << " => ";
    assert(0 <= A && A <= 1000000);
    assert(0 <= B && B <= 1000000);
    assert(0 <= C && C <= 1000000);
    assert(A + B + C >= 1);
    while (A >= 30) {
      A -= 2;
    }
    while (B >= 30) {
      B -= 2;
    }
    while (C >= 30) {
      C -= 2;
    }
    if ((A + 2 * B + 3 * C) % 2) {
      cout << "NO" << endl;
      continue;
    }
    bool ok = false;
    for (int i = 0; i <= A; i++) {
      for (int j = 0; j <= B; j++) {
        for (int k = 0; k <= C; k++) {
          if (i + 2 * j + 3 * k == (A + 2 * B + 3 * C) / 2) {
            ok = true;
          }
        }
      }
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}