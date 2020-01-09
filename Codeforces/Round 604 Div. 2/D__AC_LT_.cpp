#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  int n0, n1, n2, n3;
  cin >> n0 >> n1 >> n2 >> n3;

  int n = n0 + n1 + n2 + n3;
  if (n == 1) {
    cout << "YES\n";
    if (n0 == 1) return cout << "0\n", 0;
    if (n1 == 1) return cout << "1\n", 0;
    if (n2 == 1) return cout << "2\n", 0;
    if (n3 == 1) return cout << "3\n", 0;
  }
  if (n1 == 0 and n0 > 0) return cout << "NO\n", 0;
  if (n2 == 0 and n3 > 0) return cout << "NO\n", 0;
  bool f = false;
  if (n0 - n1 == 1 and n2 == 0) {
    cout << "YES\n0 ";
    while (n1--) cout << "1 0 ";
    return cout << "\n", 0;
  }
  if (n3 - n2 == 1 and n1 == 0 and n0 == 0) {
    cout << "YES\n3 ";
    while (n2--) cout << "2 3 ";
    return cout << "\n", 0;
  }

  // 1st 0
  int tmp = n1 - n0;
  tmp++;
  if (tmp > 0) {
    tmp = n2 - tmp;
    tmp++;
    if (tmp == n3 or tmp - 1 == n3) f = true;
  }
  if (f) {
    cout << "YES\n";
    while (n0 > 0 and n1 > 0) {
      cout << "0 1 ";
      n0--, n1--;
    }
    while (n1 > 0 and n2 > 0) {
      cout << "2 1 ";
      n1--, n2--;
    }
    while (n2 > 0 and n3 > 0) {
      cout << "2 3 ";
      n2--, n3--;
    }
    if (n2 > 0) cout << "2";
    if (n3 > 0) cout << "3";
    return cout << "\n", 0;
  }

  // 1st 1
  tmp = n1 - n0;
  if (tmp > 0) {
    tmp = n2 - tmp;
    tmp++;
    if (tmp == n3 or tmp - 1 == n3) f = true;
  }
  if (f) {
    cout << "YES\n";
    while (n0 > 0 and n1 > 0) {
      cout << "1 0 ";
      n0--, n1--;
    }
    if (n1 == 1 and n2 == 0) {
      cout << "1";
      n1--;
    }
    while (n1 > 0 and n2 > 0) {
      cout << "1 2 ";
      n1--, n2--;
    }
    if (n1 == 1 and n2 <= 0) cout << "1";
    while (n2 > 0 and n3 > 0) {
      cout << "3 2 ";
      n2--, n3--;
    }
    if (n3 > 0) cout << "3";
    if (n2 > 0) cout << "2";
    return cout << "\n", 0;
  }
  return cout << "NO\n", 0;
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