#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
// setbase - cout << setbase (16); cout << 100 << endl; Prints 64
// setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints
// xxx77 setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
// cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

#define f(i, a, b) for (i = a; i < b; i++)
#define rep(i, n) f(i, 0, n)
#define fd(i, a, b) for (i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define ss second
#define ff first
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) a.size()
#define inf (1000 * 1000 * 1000 + 5)
#define all(a) a.begin(), a.end()
#define tri pair<int, pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000 * 1000 * 1000 + 7)
#define pqueue priority_queue<int>
#define pdqueue priority_queue<int, vi, greater<int>>
#define flush fflush(stdout)
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int a[123456], b[123456];

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int i;
    rep(i, n) { cin >> a[i]; }
    if (k == 2) {
      int flag;
      rep(i, n) { b[i] = i % 2 + 1; }
      flag = 0;
      rep(i, n) {
        if (a[i] == -1)
          continue;
        if (b[i] != a[i]) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        cout << "YES" << endl;
        rep(i, n) { cout << b[i] << " "; }
        cout << endl;
        continue;
      }
      rep(i, n) { b[i] = (i + 1) % 2 + 1; }
      flag = 0;
      rep(i, n) {
        if (a[i] == -1)
          continue;
        if (b[i] != a[i]) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        cout << "YES" << endl;
        rep(i, n) { cout << b[i] << " "; }
        cout << endl;
        continue;
      }
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      rep(i, n) {
        if (a[i] != -1)
          continue;
        if (i == 0) {
          if (a[i + 1] == 1) {
            a[i] = k;
          } else {
            a[i] = 1;
          }
        } else if (i == n - 1) {
          if (a[i - 1] == 1) {
            a[i] = k;
          } else {
            a[i] = 1;
          }
        } else {
          if (a[i - 1] == 1) {
            if (a[i + 1] == 2)
              a[i] = 3;
            else
              a[i] = 2;
          } else if (a[i - 1] == 2) {
            if (a[i + 1] == 1)
              a[i] = 3;
            else
              a[i] = 1;
          } else {
            if (a[i + 1] == 2)
              a[i] = 1;
            else
              a[i] = 2;
          }
        }
      }
      rep(i, n) { cout << a[i] << " "; }
      cout << endl;
    }
  }
  return 0;
}
