#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#else
#define debug(x)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;
struct triplet{
    int x,y,gcd;
};
triplet extended_euclid(int a, int b){
    //base case
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }

    triplet smallAns = extended_euclid(b,a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)* smallAns.y;
    return ans;
}  
void solve(){
  int a,b;
  cin>>a>>b;
  triplet ans = extended_euclid(a,b);
  cout<<"gcd of a,b is "<<ans.gcd<<endl;
  cout<<"diophantine equation is "<<a<<"x"<<" + "<<b<<"y"<<" = "<<ans.gcd<<endl;
  cout<<"solution is "<<"x = "<<ans.x<<" , "<<"y = "<<ans.y<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}