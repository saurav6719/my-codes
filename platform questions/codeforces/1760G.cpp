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

void solvee(){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<n<<"."<<a<<"."<<b<<".";
    vector<vector<pp> > tree(n+5, vector<pp> ());
    for(int i = 0; i<n-1; i++){
        int u,v,w;
        cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
        cout<<u<<"."<<v<<"."<<w<<".";
    }
    cout<<endl;
}

//8.5.1.3.1.2.4.6.4.8.4.9.3.5.10.2.1.1.1.4.6.2.7.6.
void dfs(int node, int currxor, set<int> &mp, vector<vector<pp> > &tree, vector<int> &visited, int a, int b){
    debug(node);
    debug(currxor);
    visited[node] = 1;
    if(node != b) mp.insert(currxor);
    for(auto child : tree[node]){
        if(visited[child.first] == 0){
            if(node == 2) debug(child.first);
            if(child.first == b) continue;
            dfs(child.first, currxor ^ child.second, mp, tree, visited, a , b);   
        }
    }
}

void dfschahiye(int node, int currxor, set<int> &mp, vector<vector<pp> > &tree, vector<int> &visited, int a, int b){
    visited[node] = 1;
    
    if(node != a and node != b){
        mp.insert(currxor);
        // cout<<"node is "<<node<<endl;
        // cout<<"currxor is "<<currxor<<endl;
    }
    for(auto child : tree[node]){
        if(visited[child.first] == 0){
            // if(child.first == b and currxor ^ child.second != 0) continue;
            dfschahiye(child.first, currxor ^ child.second, mp, tree, visited, a , b);
        }
    }
}
void solve(){
    int n,a,b;
    cin>>n>>a>>b;

    vector<vector<pp> > tree(n+5, vector<pp> ());
    for(int i = 0; i<n-1; i++){
        int u,v,w;
        cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }

    if(a==b){
        cout<<"YES"<<endl;return;
    }



    set<int> chahiye;
    set<int> skte;

    vector<int> visited(n+5, 0);
    dfschahiye(b, 0, chahiye, tree, visited, a , b);

    // for(auto ele : chahiye){
    //     cout<<ele<<" ";
    // }
    // cout<<endl;

    vector<int> visited2(n+5, 0);

    dfs(a, 0, skte, tree, visited2, a, b);
    // for(auto ele : skte){
    //     cout<<ele<<" ";
    // }

    debug(skte.size());
    // cout<<endl;


    for(auto ele : chahiye){
        if(skte.count(ele)){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;





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
    // t = 1;
    for(int i = 1; i<=t; i++){
        solve();
    }
return 0;
}

