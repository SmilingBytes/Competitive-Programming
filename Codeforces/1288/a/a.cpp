#include <bits/stdc++.h>
#define int long long
#define EB emplace_back
#define MOD 1000000007
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define N 100005
#define inta std::vector<int>

using namespace std;

void input(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) cin >> arr[i];
}

int sumarr(vector<int> &arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) sum += arr[i];
  return sum;
}

vector<int> prearr(vector<int> &arr, int n) {
  vector<int> temp(n);
  temp[0] = arr[0];
  for (int i = 1; i < n; i++) temp[i] = temp[i - 1] + arr[i];
  return temp;
}

vector<int> postarr(vector<int> &arr, int n) {
  vector<int> temp(n);
  temp[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) temp[i] = temp[i + 1] + arr[i];
  return temp;
}

int32_t main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    int n, d, flag = 0;
    cin >> n >> d;
    int w = 1;
    if (n >= d) {
      cout << "YES" << endl;
    } else {
      for (int i = max(w, (n / 2 - 1000)); i < min(n, (n / 2 + 1000)); i++) {
        if ((ceil(((float)d) / (i + 1)) + i) <= n) {
          cout << "YES" << endl;
          flag = 1;
          break;
        }
      }
      if (flag == 0) cout << "NO" << endl;
    }
  }

  return 0;
}