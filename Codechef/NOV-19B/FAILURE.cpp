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

const int N = 100000;

vector<int> graph[N];
vector<int> cycles[N];

void addEdge(int u, int v) {
  graph[u].push_back(v);
  graph[v].push_back(u);
}

void dfs_cycle(int u, int p, int color[], int mark[], int par[],
               int& cyclenumber) {
  if (color[u] == 2) return;
  if (color[u] == 1) {
    cyclenumber++;
    int cur = p;
    mark[cur] = cyclenumber;

    while (cur != u) {
      cur = par[cur];
      mark[cur] = cyclenumber;
    }
    return;
  }
  par[u] = p;
  color[u] = 1;
  for (int v : graph[u]) {
    if (v == par[u]) continue;
    dfs_cycle(v, u, color, mark, par, cyclenumber);
  }
  color[u] = 2;
}

void printCycles(int edges, int mark[], int& cyclenumber) {
  for (int i = 1; i <= edges; i++) {
    if (mark[i] != 0) cycles[mark[i]].push_back(i);
  }
  if (cyclenumber == 1) {
    int mn = (int)1e9;
    for (int x : cycles[1]) mn = min(mn, x);
    cout << mn << "\n";
  } else if (cyclenumber < 1) {
    cout << -1 << "\n";
  } else if (cyclenumber > 1) {
    vector<int> cmn, ans;
    unordered_set<int> chk;
    for (int x : cycles[1]) chk.insert(x);
    for (int i = 2; i <= cyclenumber; i++) {
      for (int x : cycles[i]) {
        for (int d : graph[x]) {
          if (chk.count(d) == 1) cmn.push_back(d);
        }
      }
    }
  }
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
      addEdge(u, v);
    }

    int color[N];
    int par[N];
    int mark[N];
    int cyclenumber = 0;
    int edges = m;

    dfs_cycle(1, 0, color, mark, par, cyclenumber);

    // function to print the cycles
    printCycles(edges, mark, cyclenumber);
  }

#ifndef ONLINE_JUDGE
  cerr << "\nTime elapsed: " << clock() - begtime << " ms\n\n";
#endif
  return 0;
}