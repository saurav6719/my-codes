#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<map>
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
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> health(n);
    for(int i = 0; i<n; i++){
        cin>>health[i];
    }
    vector<int> position(n);
    for(int i = 0; i<n; i++){
        cin>>position[i];
    }
    map<int,int> pos;
    for(int i = 0; i<n; i++){
        int ele = position[i];
        //debug(ele);
        ele = abs(ele);
        pos[ele] += health[i];
    }
    // for(auto ele: pos){
    //     cout<<ele.first<<", "<<ele.second<<"  ;";
    // }
    int time = 0;
    int buffer = 0;
    int lasttime = 0;
    for(auto ele : pos){
        int first = ele.first;
        int second = ele.second;
        // debug(first);
        // debug(second);
        time = (first - lasttime);
        lasttime = first;
        //debug(time);
        buffer += (time * k);
        //debug(buffer);
        if(buffer < second){
            cout<<"NO"<<endl;
            return;
        }
        buffer -= second;
        //debug(buffer);
    }
    cout<<"YES"<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}