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
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
   ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  string s1, s2;
  cin >> s1 >> s2;
 
  if(s1.length() != s2.length()){
    cout << "NO" << endl;
    return;
  }
  int n = s1.length();
  vector<int> v;
  for(int i=0; i<n; i++){
    if(s1[i] != s2[i]){
      v.push_back(i);
    }
  }
  if(v.size() != 2){
    cout << "NO" << endl;
    return;
  }
 
  int index1 = v[0];
  int index2 = v[1];
 
  if(s1[index1] == s2[index2] && s1[index2] == s2[index1]){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
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