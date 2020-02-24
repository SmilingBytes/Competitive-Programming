#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#pragma GCC target("avx")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

typedef long long ll;
const int mod = 1e9 + 7;
#define INF 1000000000

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) cerr << #a << " : " << (a) << "\n";

array<list<int>, 1000 + 1> g;
int parent[1000] = {0};
int status[1000] = {0};
bool oriented = true;

void PrintCycle(int v, int u) {
  while (u != v) {
    printf("%d ", u);  // You didn't give any space after %d
    // It could not be possible to differentitate between '1''2'
    // and '12'

    u = parent[u];
  }

  printf("%d \n", v);
}

bool DFS_cycle(int u) {
  status[u] = 1;
  for (int v : g[u]) {
    if (status[v] == 0) {
      parent[v] = u;
      DFS_cycle(v);
    } else if (status[v] == 1 &&
               v != parent[u]) {  // It should be 'else if' NOT 'if'
      PrintCycle(v, u);
      break;
    }
  }
  status[u] = 2;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  int begtime = clock();
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
    register int n, m;
    cin >> n >> m;
    register int u, v;
    for (auto i = 0; i < m; i++) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    parent[1] = 1;
    DFS_cycle(1);
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}