#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
const auto start_time = chrono::steady_clock::now();
#define w(a) cerr << #a << " : " << (a) << "\n";

struct chash {
  const int RANDOM =
      (long long)(make_unique<char>().get()) ^
      chrono::high_resolution_clock::now().time_since_epoch().count();
  static unsigned long long hash_f(unsigned long long x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
  int operator()(int x) const { return hash_f(x) ^ RANDOM; }
};

unordered_map<ull, int, chash> mp;
unordered_map<ull, bool, chash> dup;
ull sq[9001];
// string dp[1000001];
vector<string> dp(1000001, "-1");
ll n;

void preCaclSquare() {
  for (register ll i = 1; i <= 9000; ++i) {
    register ull s = i * i;
    mp[s]++;
    sq[i] = s;
  }
}

bool digitDP(string &digit, int pos, ll sum) {
  if (pos < 5) {
    ll minus = (digit[pos - 1] - 48) * (digit[pos - 1] - 48);
    sum = max(0LL, (sum - minus));
    digit[pos - 1]++;
    if ((digit[pos - 1] - 48) == 10) {
      if (pos == 1) return false;
      digit[pos - 1] = '1';
      digitDP(digit, pos - 1, sum);
    } else {
      ll d = (digit[pos - 1] - 48) * (digit[pos - 1] - 48) + sum;
      digitDP(digit, pos + 1, d);
    }
  }
  if (pos == 5) {
    for (register int i = 1; i <= 9; i++) {
      ll d = (i * i) + sum;
      if (dup[d]) continue;
      dup[d] = true;
      auto it = lower_bound(sq, sq + 9000, d);
      register int j = it - (sq + 0);
      register ll k = sq[j] - d + 2;
      while (j < 9000 and k < 1000000) {
        if (dp[k] == "-1") {
          digit[pos - 1] = i + 48;
          if (k < 5) {
            string dgt = "";
            int mk = 5 - k;
            while (mk < 5) {
              dgt += digit[mk];
              mk++;
            }
            dp[k] = dgt;
          } else {
            dp[k] = digit;
          }
        }
        j++;
        k = sq[j] - d + 2;
      }
    }
    digitDP(digit, pos - 1, sum);
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  preCaclSquare();
  dp[1] = "1";
  int t;
  cin >> t;

  string digit = "11111";
  digitDP(digit, 5, 1);

  while (t--) {
    cin >> n;
    string ans = "";
    if (n > 5) {
      ll mn = n - 5;
      while (mn--) {
        ans += "1";
      }
      ans += dp[n];
      string ss = dp[n];
      mn = n - 5;
      for (auto k = 0; k < 5; k++) {
        ll d = (ss[k] - 48);
        mn += (d * d);
      }
    } else {
      string st = dp[n];
      ll sqd = 0;
      for (auto sd : st) {
        sqd += ((sd - 48) * (sd - 48));
      }
    }
  }
  int cnt = 0;
  for (register int i = 1; i <= 100000; i++) {
    if (dp[i] != "-1") cnt++;
    cout << i << " : " << dp[i] << "\n";
  }
  cout << "Counted : " << cnt << " items \n";
  cout << "Not count :" << 100000 - cnt << " items \n";
  const auto _now = chrono::steady_clock::now();
  cerr << "\nTime elapsed: "
       << chrono::duration_cast<chrono::milliseconds>(_now - start_time).count()
       << " ms\n";
  return 0;
}