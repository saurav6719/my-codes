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

void dfs(vector<vector<char> > &grid, vector<vector<int> > &visited, int i, int j, int &sz, int &maxrow, int &minrow, int &maxcol , int &mincol){
    int n = grid.size();
    int m = grid[0].size();
    visited[i][j] = 1;
    maxrow = max(maxrow , i);
    minrow = min(minrow , i);
    mincol = min(mincol, j);
    maxcol = max(maxcol, j);

    sz++;

    if(i-1 >= 0 and grid[i-1][j] == '#' and visited[i-1][j] == 0){
        dfs(grid, visited, i-1, j, sz, maxrow, minrow, maxcol, mincol);
    }
    if(j-1 >= 0 and grid[i][j-1] == '#' and visited[i][j-1] == 0){
        dfs(grid, visited, i, j-1, sz,  maxrow, minrow, maxcol, mincol);
    }

    if(i+1 < n and grid[i+1][j] == '#' and visited[i+1][j] == 0){
        dfs(grid, visited, i+1, j, sz,  maxrow, minrow, maxcol, mincol);
    }
    if(j+1 < m and grid[i][j+1] == '#' and visited[i][j+1] == 0){
        dfs(grid, visited, i, j+1, sz,  maxrow, minrow, maxcol, mincol);
    }

    
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > grid(n,vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<pp>>  rows(n, vector<pp> ());
    vector<vector<pp>> cols(m, vector<pp> ());

    vector<vector<int> > visited(n, vector<int> (m, 0));
    int curr = 1;
    for(int i = 0; i<n;i ++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '#' and visited[i][j] == 0){
                int maxrow = INT_MIN;
                int minrow = INT_MAX;
                int maxcol = INT_MIN;
                int mincol = INT_MAX;
                int sz = 0;
                dfs(grid, visited, i, j, sz, maxrow, minrow, maxcol, mincol);
                for(int r = minrow; r<=maxrow; r++){
                    rows[r].push_back({sz, curr});
                }
                for(int c = mincol; c<=maxcol; c++){
                    cols[c].push_back({sz, curr});
                }
                curr++;
            }
        }
    }

    
    int ans = 0;
    for(int i = 0; i<n; i++){
        set<pp> st;
        int curr =0;
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '.') curr++;
        }
        for(auto ele : rows[i]){
            st.insert(ele);
        }
        if(i>0) {
            for(auto ele : rows[i-1]){
                st.insert(ele);
            }
        }
        if(i+1 < n) {
            for(auto ele : rows[i+1]){
                st.insert(ele);
            }
        }

        for(auto ele : st){
            curr += ele.first;
        }
        ans = max(ans, curr);
    }

    // for(auto ele : cols[1]){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }
    // cout<<endl;

    for(int j = 0; j<m; j++){
        set<pp> st;
        int curr =0;
        for(int i = 0; i<n; i++){
            if(grid[i][j] == '.') curr++;
        }

        for(auto ele : cols[j]){
            st.insert(ele);
        }
        if(j>0) {
            for(auto ele : cols[j-1]){
                st.insert(ele);
            }
        }
        if(j+1 < m) {
            for(auto ele : cols[j+1]){
                st.insert(ele);
            }
        }

        for(auto ele : st){
            curr += ele.first;
        }
        ans = max(ans, curr);
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

