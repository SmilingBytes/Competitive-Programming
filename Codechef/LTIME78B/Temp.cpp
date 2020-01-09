#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("hin.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  int t, n, i, diff, diff1;
  cin >> t;

  while (t--) {
    cin >> n;
    int a[n + 5], b[n + 5], ans = 0;

    for (i = 0; i < n; ++i) {
      cin >> a[i];
      b[i] = 1;
    }

    sort(a, a + n);

    for (i = 0; i < n; ++i) {
      if (i == n - 1 && b[i] == 1) {
        diff = abs(a[i] - a[i - 1]);  // cout<<diff<<" ";
        if (diff == 1) {
          break;
        } else
          ans += 1;
      } else {
        diff = abs(a[i] - a[i + 1]);
        // cout<<diff<<" ";
        // //     			cout<<a[i]<<" "<<diff<<" "<<diff1<<" ";
        //      			if (0<i)
        //      			{
        //      				diff1=abs(a[i]-a[i-1]);
        //      				if (diff1==1)
        //      				{
        //      					b[i]=0; //cout<<"1st
        //      if"<<"\n";
        //      				}

        //      			}

        if (diff == 1 && b[i] == 1) {
          b[i] = 0;
          b[i + 1] = 0;
          i++;  // cout<<"2st if"<<"\n";
        } else if (a[i] - a[i - 1] == 1) {
          b[i] = 0;
        } else if (diff == 2 && b[i] == 1) {
          ans += 1;
          b[i] = 0;
          b[i + 1] = 0;
          i++;  // cout<<"3st if"<<"\n";
        } else if (2 < diff && b[i] == 1) {
          ans += 1;  // cout<<"4st if"<<"\n";
          b[i] = 0;
        }
      }
    }
    // cout<<"\n";

    cout << ans;
    cout << "\n";
  }

  // printf(" \n",)

  return 0;
}
