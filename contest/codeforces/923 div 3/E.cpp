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
    cin>>n;
    int n_copy = n;
    int k;
    cin>>k;
    vector<int> ans(n+1);
    int count = 0;
    int turn = 0;
    int start = 1;
    int last = start;
    while(count <= n){
        if(turn == 0){
            for(int i = start ; i<=n; i+=k){
                //if(n_copy <=0) break;
                debug(n_copy);
                debug(i);
                ans[i] = n_copy;
                n_copy--;
                count++;
                last = i;
            }
            if(n_copy <= 0) break;
            if(last + 1 <=n) start = last + 1;
            else start = last + 1 -k;
            turn = 1;
        }
        
        if(turn == 1){
            for(int i = start; i>=0; i-=k){
                //if(n_copy <=0) break;
                debug(n_copy);
                debug(i);
                ans[i] = n_copy;
                n_copy--;
                count++;
                last = i;
            }
            if(n_copy <= 0) break;
            start = last + 1;
            turn = 0;
        }
        
    }

    for(int i = 1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    
    
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