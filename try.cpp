/**
 *    author: Saurav
 *    created: 2024.10.31 05:48:05
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
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
struct triplet{
    int i,j,gcd;
    bool operator<(const triplet& other) const {
        if (i != other.i) return i < other.i;
        if (j != other.j) return j < other.j;
        return gcd < other.gcd;
    }
};
map<triplet,int> dp;
int f(int i, int j, int currgcd , vector<vector<int> > &grid){
    if (i == grid.size() - 1 && j == grid[0].size() - 1) {
        return __gcd(currgcd, grid[i][j]);
    }
    if(i>=grid.size() || j>=grid[0].size()){
        return 0;
    }
    triplet t = {i,j,currgcd};
    if(dp.find(t)!=dp.end()){
        return dp[t];
    }
    int ans = 0;
    ans = max(ans, f(i+1,j,__gcd(currgcd,grid[i][j]),grid));
    ans = max(ans, f(i,j+1,__gcd(currgcd,grid[i][j]),grid));
    return dp[t] = ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    dp.clear();


    int ans = f(0,0,v[0][0],v);
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

