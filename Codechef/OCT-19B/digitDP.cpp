#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

using namespace std;

typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

ll dp[20][200][2];
void getDigits(ll a, vector<ll> &digit) {
  while (a > 0) {
    digit.push_back(a % 10);
    a /= 10;
  }
}

ll digitSum(ll i, ll sum, ll tight, vector<ll> &digit) {
  // base case
  if (i == -1) return sum;
  // checking if already calculated
  if (dp[i][sum][tight] != -1 and tight != 1) return dp[i][sum][tight];
  ll ret = 0;
  ll k = (tight) ? digit[i] : 9;

  for (auto j = 0; j <= k; j++) {
    ll newTight = (digit[i] == i) ? tight : 0;
    ret += digitSum(i - 1, sum + i, newTight, digit);
    cout << ret << "\n";
  }
  cout << "\n";

  // if (tight)
  return dp[i][sum][tight] = ret;
}

ll rangeDigitSum(ll a, ll b) {
  memset(dp, -1, sizeof(dp));
  vector<ll> dA;
  getDigits(b - 1, dA);
  ll ans1 = digitSum(sz(dA) - 1, 0, 1, dA);
  return ans1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  ll a, b;
  cin >> a >> b;
  rangeDigitSum(a, b);

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}