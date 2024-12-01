/**
 *    author: Saurav
 *    created: 2024.11.30 20:01:02
 **/

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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
// #define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
vector<vector<int> > dp;
int f(int i, int j , vector<vector<char> > &grid, int n, int m){
    if(i<0 or i>=n or j<0 or j>=m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(grid[i][j] == 'U'){
        if(i-1>=0 and grid[i-1][j] == '?'){
            grid[i-1][j] = 'D';
            return dp[i][j] = 1;
        }
        if(i-1>=0 and grid[i-1][j] == 'D'){
            return dp[i][j] = 1;
        }
        return dp[i][j] = f(i-1,j,grid,n,m);
    }
    if(grid[i][j] == 'D'){
        if(i+1<n and grid[i+1][j] == '?'){
            grid[i+1][j] = 'U';
            return dp[i][j] = 1;
        }
        if(i+1<n and grid[i+1][j] == 'U'){
            return dp[i][j] = 1;
        }
        return dp[i][j] = f(i+1,j,grid,n,m);
    }
    if(grid[i][j] == 'L'){
        if(j-1>=0 and grid[i][j-1] == '?'){
            grid[i][j-1] = 'R';
            return dp[i][j] = 1;
        }
        if(j-1>=0 and grid[i][j-1] == 'R'){
            return dp[i][j] = 1;
        }
        return dp[i][j] = f(i,j-1,grid,n,m);
    }
    if(grid[i][j] == 'R'){
        if(j+1<m and grid[i][j+1] == '?'){
            grid[i][j+1] = 'L';
            return dp[i][j] = 1;
        }
        if(j+1 < m and grid[i][j+1] == 'L'){
            return dp[i][j] = 1;
        }

        return dp[i][j] = f(i,j+1,grid,n,m);
    }
    if(grid[i][j] == '?'){
        char left = '.';
        char right = '.';
        char up = '.';
        char down = '.';
        if(j-1>=0) left = grid[i][j-1];
        if(j+1<m) right = grid[i][j+1];
        if(i-1>=0) up = grid[i-1][j];
        if(i+1<n) down = grid[i+1][j];

        if(left == '?' or right == '?' or up == '?' or down == '?'){
            return dp[i][j] = 1;
        }

        int leftans = f(i,j-1,grid,n,m);
        int rightans = f(i,j+1,grid,n,m);
        int upans = f(i-1,j,grid,n,m);
        int downans = f(i+1,j,grid,n,m);

        return dp[i][j] = (leftans or rightans or upans or downans);
    }
    return 0;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > grid(n,vector<char> (m)) ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j] ;
        }
    }
    dp.assign(n+1,vector<int> (m+1,-1)) ;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dp[i][j] == -1){
                f(i,j,grid,n,m) ;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans += dp[i][j] ;
        }
    }

    cout<<ans<<endl;

}
/* logic ends */

signed main(){
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
 