#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<bitset>
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

string getbinary(int x, int n){
    bitset<17> b(x);
    string ans = b.to_string().substr(17-n);
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    int x = 1;
    while(x != n){
        int curr = (1<<x);
        int i = v.size()- 1;
        while(i>=0){
            v.push_back(v[i] | curr);
            i--;
        }
        x++;
    }
    for(int i = 0; i<v.size(); i++){
        cout<<getbinary(v[i], n)<<endl;
        
    }
    
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