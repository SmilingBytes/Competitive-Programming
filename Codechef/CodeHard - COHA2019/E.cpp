#include <bits/stdc++.h>
using namespace std;

// Function that returns the N-th character
char NthCharacter(int n) {
  string s = "";
  int c = 1;
  for (int i = 1;; i++) {
    if (c < 10)
      s += char(48 + c);
    else {
      string s1 = "";
      int dup = c;
      while (dup) {
        s1 += char((dup % 10) + 48);
        dup /= 10;
      }
      reverse(s1.begin(), s1.end());
      s += s1;
    }
    c++;

    // if the length exceeds N
    if (s.length() >= n) {
      return s[n - 1];
    }
  }
}

int main() {
  int n;

  std::cin >> n;
  cout << NthCharacter(n);

  return 0;
}
