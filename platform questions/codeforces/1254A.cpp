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
void dfs(vector<vector<char>>&graph, vector<vector<int> > &visited, int i, int j, vector<char> &symbols, map<char,int> &req, map<char,int> &curr, int currsymbol, vector<vector<char> > &ans, int k){
    int n = graph.size();
    int m = graph[0].size();
    visited[i][j] = 1;
    ans[i][j] = symbols[currsymbol];
    if(graph[i][j] == 'R') curr[symbols[currsymbol]]++;
    if(curr[symbols[currsymbol]] == req[symbols[currsymbol]] and currsymbol < k-1) currsymbol++;
    //up 
    if(i-1>=0 and visited[i-1][j] == 0){
        dfs(graph, visited, i-1, j, symbols, req, curr, currsymbol, ans,k);
    }
    //down
    if(i+1<n and visited[i+1][j] == 0){
        dfs(graph, visited, i+1, j, symbols, req, curr, currsymbol, ans,k);
    }
    //right
    if(j+1<m and visited[i][j+1] == 0){
        dfs(graph, visited, i, j+1, symbols, req, curr, currsymbol, ans,k);
    }
    //left
    if(j-1>=0 and visited[i][j-1] == 0){
        dfs(graph, visited, i, j-1, symbols, req, curr, currsymbol, ans,k);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    int cnt = 0;
    vector<vector<char> > graph(n, vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>graph[i][j];
            if(graph[i][j] == 'R') cnt++;
        }
    }
    debug(cnt);

    vector<char> symbols;
    for(char i = 'a' ; i<='z' ; i++){
        symbols.push_back(i);
    }
    for(char i = 'A' ; i<='Z' ; i++){
        symbols.push_back(i);
    }
    for(char i = '0' ; i<='9' ; i++){
        symbols.push_back(i);
    }

    sort(symbols.begin(), symbols.end());

    map<char,int> curr;
    for(auto ele : symbols){
        curr[ele] = 0;
    }

    map<char,int> req = curr;

    int xx = cnt / k;
    debug(xx);
    for(int i = 0; i<k; i++){
        req[symbols[i]] = xx;
        debug(symbols[i]);
    }
    int md = cnt % k;
    for(int i = 0; i<md; i++){
        req[symbols[i]]++;
    }

    printmap(req);

    vector<vector<char> > ans(n, vector<char> (m));
    vector<vector<int> > visited(n, vector<int>(m));


    dfs(graph, visited, 0,0,symbols,req, curr, 0,ans,k);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<ans[i][j];
        }
        cout<<endl;
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

