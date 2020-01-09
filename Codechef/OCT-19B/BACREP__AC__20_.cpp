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

void del_p(vector<set<ll> > &v, ll i) {
  if (v[i].empty() == false) {
    for (auto x : v[i]) {
      v[x].erase(i);
      del_p(v, x);
    }
  }
}
void doIt(vector<set<ll> > &v, ll i, vector<ll> &a, ll p) {
  if (v[i].empty() == false) {
    for (auto x : v[i]) {
      if (v[x].empty()) {
        a[x] += a[i];
      } else {
        doIt(v, x, a, i);
      }
    }
    a[i] = a[p];
  }
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

  ll n, q;
  cin >> n >> q;
  vector<set<ll> > v(n + 1);

  for (register ll i = 1; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    v[x].insert(y);
    v[y].insert(x);
  }
  del_p(v, 1);
  vector<ll> a(n + 1);
  ll b(n + 1);
  for (auto i = 1; i <= n; i++) cin >> a[i];
  for (auto i = 0; i < q; i++) {
    char op;
    ll node, k;
    cin >> op >> node;
    doIt(v, 1, a, 0);
    if (op == '+') {
      cin >> k;
      a[node] += k;
    } else
      cout << a[node] << "\n";

    cerr << "\nDebug a: \n";
    for (const auto val : a) cerr << val << " ";
    cerr << "\n";
  }
  // for (auto x : v) {
  //   for (auto d : x) cout << d << " ";
  //   cout << "\n";
  // }

#ifndef ONLINE_JUDGE
  std::cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}