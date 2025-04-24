/**
 *    author: Saurav
 *    created: 2024.11.06 01:18:17
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

void dfs11(vector<vector<char> > &grid, vector<vector<int> > &cellsreachablefrom1, int i, int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='#') return ;
    if(cellsreachablefrom1[i][j]) return ;
    cellsreachablefrom1[i][j] = 1;
    dfs11(grid,cellsreachablefrom1,i+1,j);
    dfs11(grid,cellsreachablefrom1,i,j+1);
}

void dfs22(vector<vector<char> > &grid, vector<vector<int> > &cellsreachablefrom2, int i, int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='#') return ;
    if(cellsreachablefrom2[i][j]) return ;
    cellsreachablefrom2[i][j] = 1;
    dfs22(grid,cellsreachablefrom2,i-1,j);
    dfs22(grid,cellsreachablefrom2,i,j-1);
}

void dfs33(vector<vector<char> > &grid, vector<vector<int> > &distance, int i, int j, int d, vector<vector<int> > &visited){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='#' || distance[i][j]<=d) return ;
    if(visited[i][j]) return ;
    visited[i][j] = 1;
    distance[i][j] = d;
    dfs33(grid,distance,i+1,j,d+1, visited);
    dfs33(grid,distance,i,j+1,d+1, visited);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > grid(n,vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int> > cellsreachablefrom11(n,vector<int>(m,0));
    vector<vector<int> > cellsreachablefromnm(n,vector<int>(m,0));

    dfs11(grid,cellsreachablefrom11,0,0);
    dfs22(grid,cellsreachablefromnm,n-1,m-1);

    vector<pp> intersectingcells;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(cellsreachablefrom11[i][j] && cellsreachablefromnm[i][j]){
                intersectingcells.push_back({i,j});
            }
        }
    }

    vector<vector<int> > distance(n,vector<int>(m,INT_MAX));
    vector<vector<int> > visited(n,vector<int>(m,0));
    dfs33(grid,distance,0,0,0,visited);

    if(distance[n-1][m-1] == INT_MAX){
        cout<<0<<endl;
        return ;
    }

    map<int,int> mp;
    for(auto x : intersectingcells){
        if(x.first == 0 && x.second == 0) continue ;
        if(x.first == n-1 && x.second == m-1) continue ;
        int dist = distance[x.first][x.second];
        mp[dist]++;
    }

    for(auto ele : mp){
        if(ele.second == 1){
            cout<<1<<endl;
            return;
        }
    }

    cout<<2<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

