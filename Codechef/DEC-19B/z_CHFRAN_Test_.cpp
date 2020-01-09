#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define w(a) std::cerr << #a << " : " << (a) << "\n";

const int N = 1000001;

// Utility method to add value val, to range [lo, hi]
void add(vector<int>& arr, int lo, int hi, int val) {
  arr[lo] += val;
  arr[hi + 1] -= val;
}

// Utility method to get actual array from operation array
void updateArray(vector<int>& arr) {
  // convert array into prefix sum array
  for (int i = 1; i < N; i++) arr[i] += arr[i - 1];
}

bool solve(int n, priority_queue<pair<int, int>>& st, int a, int b) {
  priority_queue<int> end;
  int cnt = 1, s, e;
  end.push(st.top().second);
  st.pop();
  int ans = 1e5;
  while (!st.empty()) {
    s = (-1) * st.top().first;
    e = (-1) * end.top();
    if (s < e) {
      end.push(st.top().second);
      st.pop();
      if (s > a and s < b and ans > cnt) ans = cnt;
      cnt++;
    } else if (s > e) {
      end.pop();
      cnt--;
      if (e >= a and e < b and ans > cnt) ans = cnt;
      if (end.empty() and !st.empty()) {
        end.push(st.top().second);
        st.pop();
        cnt++;
      }
    } else {
      int tmp = cnt + 1;
      end.pop();
      end.push(st.top().second);
      st.pop();
      if (e > a and e < b and ans > cnt) ans = cnt;
    }
    if (ans == 0) return cout << 0 << "\n", 0;
  }

  cout << ans << '\n';
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("outTest.txt", "w", stdout);
#endif
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> arr(N, 0);
    arr.reserve(1000000009);
    int a = 1e9, b = 0;
    priority_queue<pair<int, int>> st;
    for (register int i = 0, l, r; i < n; i++) {
      cin >> l >> r;
      a = min(r, a);
      b = max(l, b);
      add(arr, l, r - 1, 1);
      st.push(make_pair(-1 * l, -1 * r));
    }
    if (a >= b) {
      cout << -1 << "\n";
      continue;
    }
    if (b >= N) {
      solve(n, st, a, b);
      continue;
    }
    updateArray(arr);
    int ans = 1e9;
    for (register int i = a; i < b; i++) ans = min(ans, arr[i]);
    cout << ans << '\n';
  }
  return 0;
}