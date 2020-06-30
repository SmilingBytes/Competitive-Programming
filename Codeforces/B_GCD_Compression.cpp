/**
 *    author:  ismail
 *    created: 20.06.2020  21:09:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr<< #a <<" : " << (a) <<"\n";

void solve(){
  int n;
  cin >> n;
  vector<int> a, b;
  for (int i = 1, d; i <= 2*n; i++){
    cin >> d;
    if(d%2 == 0){
      a.push_back(i);
    }else{
      b.push_back(i);
    }
  }
  int na = a.size(), nb = b.size();
  int out = 0;
  na = na - na%2;
  for (int i = 0; i < na; i+=2){
    cout << a[i]<<" "<<a[i+1] << "\n";
    out++;
    if(out == n-1) return;
  }
  for (int i = 0; i < nb; i+=2){
    cout << b[i]<<" "<<b[i+1] << "\n";
    out++;
    if(out == n-1) return;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int test; cin >> test;
  while(test--)solve();
  
  return 0;
}