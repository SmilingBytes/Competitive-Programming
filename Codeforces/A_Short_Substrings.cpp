#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define w(a) cerr << #a << " : " << (a) << "\n";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    string b, a = "";
    cin >> b;
    int n = (int)b.size();
    a.push_back(b[0]);
    for (int i = 1; i < n - 1; i += 2) a.push_back(char(b[i]));
    a.push_back(b[n - 1]);
    cout << a << '\n';
  }
  return 0;
}