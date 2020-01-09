#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
const auto start_time = chrono::steady_clock::now();
#define w(a) std::cerr << #a << " : " << (a) << "\n";

bool solve() {
  ll a, b;
  cin >> a >> b;
  if (a == 2 * b or b == 2 * a) return cout << "YES\n", 0;
  ll aa = max(a, b);
  ll bb = min(a, b);
  if (aa > 2 * bb) return cout << "NO\n", 0;
  ll d1 = aa / 2;
  ll dif = bb - d1;
  ll rem = dif / 2;
  b = bb - (rem * 2);
  a = aa - rem;
  if (a == 2 * b or b == 2 * a) return cout << "YES\n", 0;
  d1 = a / 2;
  b = b - d1;
  a = a - (d1 * 2);
  if (a == 2 * b or b == 2 * a) return cout << "YES\n", 0;
  return cout << "NO\n", 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  register int tc;
  cin >> tc;
  while (tc--) solve();

  const auto _now = chrono::steady_clock::now();
  cerr << "\nTime elapsed: "
       << chrono::duration_cast<chrono::milliseconds>(_now - start_time).count()
       << " ms\n";
  return 0;
}