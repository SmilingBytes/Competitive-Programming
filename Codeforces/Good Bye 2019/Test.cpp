#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()

// Gonna use 1-based indexing here!
const int len = 650;
const int maxN = 100005;

struct node {
  int L, R, q;
} A[maxN];

int N, K, Q;
vi T(maxN), B(maxN);
vector<ll> P(maxN), Sol(maxN);
tr1::unordered_map<ll, int> Cnt;

bool comp(node a, node b) {
  if (B[a.L] == B[b.L]) return a.R < b.R;
  return B[a.L] < B[b.L];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;

  for (int x = 1; x <= N; x++) {
    cin >> T[x];
    B[x] = x / len;
  }

  for (int x = 1; x <= N; x++) {
    P[x] = P[x - 1];

    int i;
    cin >> i;
    P[x] += T[x] == 1 ? i : -i;
  }

  cin >> Q;

  for (int q = 0; q < Q; q++) {
    int l, r;
    cin >> l >> r;
    A[q] = {l - 1, r, q};
  }

  sort(A, A + Q, comp);

  int moL = 0, moR = 0;
  ll ans = 0;
  Cnt[0]++;

  for (int x = 0; x < Q; x++) {
    int L = A[x].L, R = A[x].R;

    while (moR < R) {
      moR++;
      ans += Cnt[P[moR] - K];
      Cnt[P[moR]]++;
    }
    while (moR > R) {
      Cnt[P[moR]]--;
      ans -= Cnt[P[moR] - K];
      moR--;
    }

    while (moL > L) {
      moL--;
      ans += Cnt[P[moL] + K];
      Cnt[P[moL]]++;
    }
    while (moL < L) {
      Cnt[P[moL]]--;
      ans -= Cnt[P[moL] + K];
      moL++;
    }
    Sol[A[x].q] = ans;
  }

  for (int x = 0; x < Q; x++) cout << Sol[x] << endl;

  /*
  @todo 877F
  @body Fix this stupid bug somewhere!
  */

  return 0;
}