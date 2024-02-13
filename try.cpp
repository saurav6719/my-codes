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
    int n;
    int x;
    int y;
    cin>>n>>x>>y;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    
    vector<vector<int> > modx(x, vector<int> ());
    vector<vector<int> > mody(y, vector<int> ());
    for(int i = 0; i<n; i++){
        int a = input[i] % x;
        //debug(a);
        modx[a].push_back(i);

        int b = input[i] % y;
        //debug(b);
        mody[b].push_back(i);
    }

    
    int ans = 0;
    for(int i = 0; i<n; i++){
        unordered_set<int> st;
        // cout<<endl;
        // cout<<endl;
        // debug(i);
        int d = input[i] % x;
        //debug(d);
        int c = x - d;
        if(c == x) c = 0;
        //debug(c);
        // for(int i = 0; i<modx[c].size(); i++){
        //     cout<<modx[c][i]<<" ";
        // }
        // cout<<endl;
        for(int j = 0; j<modx[c].size(); j++){
            if(modx[c][j] != i) {
                st.insert(modx[c][j]);
                //debug(modx[c][j]);
            }
        }

        int size = modx.size();
        
        // for(auto ele: st){
        //     cout<<"st"<<ele<<" ";
        // }
        // cout<<endl;

        int e = input[i] % y;
        //debug(e);
        int f = e;
        if(f==y) f=0;
        //debug(f);
        // for(int i = 0; i<mody[f].size(); i++){
        //     cout<<mody[f][i]<<" ";
        // }
        // cout<<endl;
        for(int k = 0;k<mody[f].size();k++){
            if(mody[f][k] > i and  st.count(mody[f][k])) {
                //cout<<mody[f][k]<<endl;
                ans ++;
                //debug(ans);
            }
        }
    }
    cout<<ans<<endl;
    
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