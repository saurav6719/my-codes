#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c));
#define mx(a,b,c) max(a,max(b,c));
using namespace std;
void solve(){ios_base::sync_with_stdio(false);cin.tie(NULL);
    string s;
    cin>>s;
    unordered_map<char,int> mp;
    for(int i = 0; i<s.size(); i++){
        mp[s[i]]++;
    }
    int ans = 0;
    bool flag = false;
    for(auto ele: mp){
        if(ele.second % 2 == 0){ // even number of characters
            ans += ele.second;
        }
        else{
            ans += ele.second-1;
            flag = true;
        }
    }
    if(flag) ans++;
    cout<<ans<<endl;

}
int32_t main(){
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}