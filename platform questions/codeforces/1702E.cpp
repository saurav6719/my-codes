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

bool dfs(int node , vector<int> &visited, vector<int> &mark, vector<vector<int>> &graph, int curr){
    visited[node] = 1;
    mark[node] = curr;
    for(auto child : graph[node]){
        if(visited[child] == 1){
            if(mark[child] == curr){
                return false;
            }
        }
        else{
            bool xx = dfs(child, visited, mark, graph, (curr == 1) ? 2 : 1);
            if(!xx) return false;
        }
    }

    return true;
}
void solve(){
    int n;
    cin>>n;

    vector<pp> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first>>input[i].second;
    }

    for(int i = 0; i<n; i++){
        if(input[i].first == input[i].second){
            cout<<"NO"<<endl;
            return;
        }
    }

    map<int,vector<int> > mp;

    for(int i = 0; i<n; i++){
        int a = input[i].first;
        int b = input[i].second;
        mp[a].push_back(i);
        mp[b].push_back(i);

        if(mp[a].size() > 2){
            cout<<"NO"<<endl;
            return;
        }

        if(mp[b].size() > 2){
            cout<<"NO"<<endl;
            return;
        }

    }

    vector<vector<int>> graph(n, vector<int> ());

    for(int i = 0; i<n; i++){
        int a = input[i].first;
        int b = input[i].second;
        for(auto ele : mp[a]){
            if(ele!=i) graph[i].push_back(ele);
        }
        for(auto ele : mp[b]){
            if(ele!=i) graph[i].push_back(ele);
        }
    }

    // print2d(graph);


    vector<int> visited(n, -1);

    vector<int> mark(n);

    for(int i = 0; i<n; i++){
        if(visited[i] == -1){
            bool xx = dfs(i, visited, mark, graph, 1);
            if(xx == false){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
    
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

