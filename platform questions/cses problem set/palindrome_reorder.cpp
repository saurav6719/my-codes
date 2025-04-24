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
void solve(){
    string str;
    cin>>str;
    unordered_map<char,int> mp;
    int n = str.size();
    for(int i = 0; i<n; i++){
        mp[str[i]]++;
    }
    int count = 0;
    for(auto ele : mp){
        if(ele.second & 1) count++;
    }
    if(count > 1){
        cout<<"NO SOLUTION";
        return;
    }
    string ans1 = "";
    string ans2 = "";
    string ans3 = "";
    bool flag = false;
    for(auto ele:mp ){
        if(ele.second & 1 and not flag){
            ans3 += ele.first;
            flag = true;
            ele.second--;
        }
        for(int i = 0; i<(ele.second/2); i++){
            ans1 += ele.first;
        }
        for(int i = ele.second/2; i<ele.second; i++){
            ans2 += ele.first;
        }
    }

    ans1+= ans3;
    reverse (ans2.begin(), ans2.end());
    ans1+= ans2;
    cout<<ans1;
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