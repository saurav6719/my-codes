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
int ans = 0;
unordered_set<string> vis;
bool cango(string &input, int i, int j, int count){
    debug(i);
    debug(j);
    debug(count);
    string str ="";
    str+= to_string(i);
    str+= '>';
    str+= to_string(j);
    debug(str);
    if(vis.count(str)) return false;
    if(count!=48 and i==6 and j==0) return false; 
    if(i<0 or j<0 or i==7 or j==7) return false;
    if(input[count] == '?') return true;
}
void f(string &input, int i, int j, int count){
    if(count == 48 and i==6 and j==0) {
        ans++;
        return;
    }
    string str ="";
    str+= to_string(i);
    str+= '>';
    str+= to_string(j);
    vis.insert(str);
    if(cango(input,i+1,j,count+1)) f(input,i+1,j,count+1);
    if(cango(input,i,j+1,count+1)) f(input,i,j+1,count+1);
    if(cango(input,i-1,j,count+1)) f(input,i-1,j,count+1);
    if(cango(input,i,j-1,count+1)) f(input,i,j-1,count+1);
    debug(i);
    debug(j);
    debug(count);
    if(input[count+1] == 'R') f(input,i,j+1,count+1);
    if(input[count+1] == 'L') f(input,i,j-1,count+1);
    if(input[count+1] == 'U') f(input,i-1,j,count+1);
    if(input[count+1] == 'D') f(input,i+1,j,count+1);
    vis.erase(str);
}

void solve(){
    string str;
    cin>>str;
    f(str,0,0,0);
    cout<<ans;
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