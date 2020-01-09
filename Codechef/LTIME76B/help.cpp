#include <bits/stdc++.h>
#include <map>
#define ll long long int

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out_help.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    int op, a, b;
    int SA = 0, SB = 0, flag = 0;

    while (n--) {
      cin >> op >> a >> b;

      if (flag == 0 && op == 2) {
        cout << "NO" << endl;
        flag = 1;
      } else if (op == 1) {
        cout << "YES" << endl;
        SA = a;
        SB = b;
      } else if (op == 2) {
        int mx = max(a, b);
        int mn = min(a, b);
        if (a == b) {
          cout << "YES" << endl;
          SA = a;
          SB = b;
        } else if (SA == SB && a != b) {
          cout << "NO" << endl;
        } else if ((SA >= mn && SA <= mx) || (SB >= mn && SB <= mx)) {
          cout << "NO" << endl;
        } else if (SA >= mn && SA <= mx && SB <= SA && SB <= mn) {
          cout << "YES" << endl;
          SA = mx;
          SB = mn;
        } else if (SB >= mn && SB <= mx && SA <= SB && SA <= mn) {
          cout << "YES" << endl;
          SA = mn;
          SB = mx;
        } else {
          cout << "NO" << endl;
        }
      }
      //   cout<<"SA "<<SA<<" SB "<<SB<<endl;
    }
  }

  return 0;
}
