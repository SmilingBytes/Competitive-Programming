#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
const auto start_time = chrono::steady_clock::now();
#define w(a) std::cerr << #a << " : " << (a) << "\n";

const int M = (int)10;
const bitset<M> Z;

inline void addition(bitset<M> &a, bitset<M> &b) {
  register int cnt = 0;
  while (!b.none()) {
    cout << "A = " << a << "\n";
    cout << "B = " << b << "\n";

    bitset<M> v = a & b;
    a = a ^ b;
    b = v << 1;
    cnt++;
  }
  cout << cnt << "\n";
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
  while (tc--) {
    string s1, s2;
    cin >> s1 >> s2;
    bitset<M> a(s1);
    bitset<M> b(s2);
    addition(a, b);
  }
  return 0;
}