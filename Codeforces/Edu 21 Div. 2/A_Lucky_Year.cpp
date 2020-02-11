/**
 *    author:  ismail
 *    created: 11.02.2020  12:07:43
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n < 10)
    cout << 1 << "\n";
  else {
    int dgt = 0, fst = 0, num = n;
    while (num > 0) {
      fst = num % 10;
      num /= 10;
      dgt++;
    }
    if (fst == 9) {
      int year = 1;
      for (int i = 0; i < dgt; i++) year *= 10;
      cout << year - n << "\n";
    } else {
      int year = fst + 1;
      for (int i = 1; i < dgt; i++) year *= 10;
      cout << year - n << "\n";
    }
  }
  return 0;
}