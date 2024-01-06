#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#define ll long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
void solve(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;
  int l = -1e9, r = +1e9;
  while(n--){
    string s;
    cin >> s;
    int num;
    cin >> num;
    char ch;
    cin >> ch;
 
    if(s == "<" && num == -1e9 && ch == 'Y' || s == ">=" && num == -1e9 && ch == 'N'){
      cout << "-1000000001" << endl;
      return;
    }
    if(s == ">" && num == +1e9 && ch == 'Y' || s == "<=" && num == 1e9 && ch == 'N'){
      cout << "1000000001" << endl;
      return;
    }
 
    if(s == ">=" && ch == 'Y'){
      l = max(num, l);
    }
    else if(s == ">=" && ch == 'N'){
      r = min(r, num-1);
    }
    else if(s == "<=" && ch == 'Y'){
      r = min(r, num);
    }
    else if(s == "<=" && ch == 'N'){
      l = max(l, num+1);
    }
    else if(s == ">" && ch == 'Y'){
      l = max(l, num+1);
    }
    else if(s == ">" && ch == 'N'){
      r = min(r, num);
    }
    else if(s == "<" && ch == 'Y'){
      r = min(r, num-1);
    }
    else if(s == "<" && ch == 'N'){
      l = max(l, num);
    } 
  }
  if(l > r){
    cout << "Impossible" << endl;
  }
  else{
    cout << l << endl;
  }
}
int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
    solve();
    }
return 0;
}
