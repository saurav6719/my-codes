/**
 *    author: Saurav
 *    created: 2024.11.19 22:35:19
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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '<'){
                for(int k = j-1; k>=0; k--){
                    if(grid[i][k] == '.'){
                        grid[i][k] = '#';
                    }
                    else break;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '>'){
                for(int k = j+1; k<m; k++){
                    if(grid[i][k] == '.'){
                        grid[i][k] = '#';
                    }
                    else break;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '^'){
                for(int k = i-1; k>=0; k--){
                    if(grid[k][j] == '.'){
                        grid[k][j] = '#';
                    }
                    else break;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 'v'){
                for(int k = i+1; k<n; k++){
                    if(grid[k][j] == '.'){
                        grid[k][j] = '#';
                    }
                    else break;
                }
            }
        }
    }


    //bfs

    int start_x = -1, start_y = -1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 'S'){
                start_x = i;
                start_y = j;
                break;
            }
        }
    }

    int end_x = -1, end_y = -1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 'G'){
                end_x = i;
                end_y = j;
                break;
            }
        }
    }

    debug(end_x);
    debug(end_y);

    print2d(grid);

    queue<pp> q;

    vector<vector<int> > visited(n,vector<int>(m,0));
    vector<vector<int> > dist(n,vector<int>(m,0));
    q.push({start_x,start_y});
    visited[start_x][start_y] = 1;
    dist[start_x][start_y] = 0;
    while(!q.empty()){
        int curr_x = q.front().first;
        int curr_y = q.front().second;
        debug(curr_x);
        debug(curr_y);
        q.pop();
        if(curr_x == end_x && curr_y == end_y){
            cout<<dist[curr_x][curr_y]<<endl;
            return;
        }
        if(curr_x-1>=0 && visited[curr_x-1][curr_y] == 0 && (grid[curr_x-1][curr_y] == '.' || grid[curr_x-1][curr_y] == 'G') ){
            visited[curr_x-1][curr_y] = 1;
            dist[curr_x-1][curr_y] = dist[curr_x][curr_y] + 1;
            q.push({curr_x-1,curr_y});
        }
        if(curr_x+1<n && visited[curr_x+1][curr_y] == 0 && (grid[curr_x+1][curr_y] == '.' || grid[curr_x+1][curr_y] == 'G') ){
            visited[curr_x+1][curr_y] = 1;
            dist[curr_x+1][curr_y] = dist[curr_x][curr_y] + 1;
            q.push({curr_x+1,curr_y});
        }
        if(curr_y-1>=0 && visited[curr_x][curr_y-1] == 0 && (grid[curr_x][curr_y-1] == '.' || grid[curr_x][curr_y-1] == 'G') ){
            visited[curr_x][curr_y-1] = 1;
            dist[curr_x][curr_y-1] = dist[curr_x][curr_y] + 1;
            q.push({curr_x,curr_y-1});
        }
        if(curr_y+1<m && visited[curr_x][curr_y+1] == 0 && (grid[curr_x][curr_y+1] == '.' || grid[curr_x][curr_y+1] == 'G') ){
            visited[curr_x][curr_y+1] = 1;
            dist[curr_x][curr_y+1] = dist[curr_x][curr_y] + 1;
            q.push({curr_x,curr_y+1});
        }
    }

    if(visited[end_x][end_y] == 0){
        cout<<-1<<endl;
    }
    else{
        cout<<dist[end_x][end_y]<<endl;
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

