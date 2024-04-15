/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */

/// not correct solution 


void solve(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int> > grid(n, vector<int> (m));
    vector<vector<pair<bool,int> > > dp(n+5, vector<pair<bool,int> >(1027, {false,-1}));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    //base case 

    for(int j = 0 ; j<m; j++){
        dp[0][grid[0][j]].first = true;
        dp[0][grid[0][j]].second = j+1;
    }

    for(int i = 1; i<n; i++){
        for(int x = 1; x<=1023; x++){
            for(int j = 0; j<m;j++){
                int ele = grid[i][j];
                
                int chahiye = x ^ ele;
                
                if(dp[i-1][chahiye].first){
                    debug(ele);
                    debug(j);
                    debug(chahiye);
                    debug(x);
                    dp[i][x].first = true;
                    dp[i][x].second = j+1;
                }
            }
        }
    }

    bool poss = false;

    int xx = -1;

    for(int i = 1; i<=1023; i++){
        if(dp[n-1][i].first){
            debug(i);
            poss = true;
            xx = dp[n-1][i].second;
            break;
        }
    }

    vector<int> ans;
    if(!poss){
        cout<<"NIE"<<endl;
        return;
    }
    else{
        cout<<"TAK"<<endl;
        ans.push_back(xx);
        debug(xx);
        int i = n-2;
        int ele = grid[n-1][xx-1];
        debug(ele);
        while(i>=0){
            for(int j = 0; j<m; j++){
                int element = grid[i][j];
                int xori = ele ^ element;
                debug(xori);
                if(dp[i][xori].first){
                    ans.push_back(dp[i][xori].second);
                    ele = grid[i][j];
                    break;
                }
            }
            i--;
        }
    }

    reverse(ans.begin(),ans.end());
    for(auto ele : ans){
        cout<<ele<<" ";
    }

}
/* logic ends */

signed main(){
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

