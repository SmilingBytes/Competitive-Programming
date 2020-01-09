#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int arr[N];

int dp[N][N][N][2];

int solve(int pos, int zero, int one, int lst) {
  if (one < 0 || zero < 0) return 1e9;

  if (pos == n) {
    return 0;
  }

  int &ret = dp[pos][zero][one][lst];
  if (ret != -1) {
    return ret;
  }

  ret = 1e9;
  if (arr[pos] == 0) {
    ret = solve(pos + 1, zero - 1, one, 0) + (lst == 1);
    ret = min(ret, solve(pos + 1, zero, one - 1, 1) + (lst == 0));
  } else {
    ret = solve(pos + 1, zero, one, arr[pos] % 2) + (arr[pos] % 2 != lst);
  }

  return ret;
}

void read() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

int work() {
  memset(dp, -1, sizeof dp);

  int zero = n / 2;
  int one = n - zero;

  for (int i = 0; i < n; i++) {
    if (arr[i] > 0) {
      if (arr[i] % 2 == 0)
        zero--;
      else
        one--;
    }
  }

  int ret = solve(0, zero, one, 0);
  ret = min(ret, solve(0, zero, one, 1));
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  read();
  cout << work() << endl;
  return 0;
}