/**
 *    author:  ismail
 *    created: 18.06.2020  20:52:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define w(a) std::cerr<< #a <<" : " << (a) <<"\n";

void solve(){
  int a,b,n;
  cin >> a>>b>>n;
  int ans = 0;
  if(a>n or b>n) {
    cout << 0 << "\n";
    return;
  }
  while(a<=n or b<=n){
      ans++;
    if(a+b>n)break;
    if(a>b){
      b += a;
    }else{
      a+=b;
    }
  }
  cout << ans << "\n";
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int test; cin >> test;
  while(test--)solve();
  
  return 0;
}