#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
const int mod = 1e9 + 7;

#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k;
  deque<ll> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  a.push_front(5);
  for (const auto val : a) cout << val << " ";
  cout << "\n";

  a.pop_back();
  a.pop_back();
  for (const auto val : a) cout << val << " ";

  return 0;
}