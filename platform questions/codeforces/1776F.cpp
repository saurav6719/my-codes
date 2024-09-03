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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+5, vector<int> ());
    vector<pp> edgelist;

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edgelist.push_back({u,v});
    }

    vector<int> visited(n+5, 0);

    bool found = false;



    for(int i = 1; i<=n; i++){
        if(graph[i].size() < n-1){
            debug(i);
            debug(graph[i].size());
            visited[i] = 1;
            found = true;
            for(auto ele : graph[i]){
                visited[ele] = 1;
            }
            break;
        }
    }

    debug(found);

    if(!found){
        vector<int> answer(m);
        bool given = false;
        for(int i = 0; i<m; i++){
            if(edgelist[i].first == 1 or edgelist[i].second==1){
                if(!given) {
                    answer[i] = 2;
                    given = true;
                }
                else answer[i] = 3;
            }
            else answer[i] = 1;
        }
        print(answer);

        cout<<3<<endl;

        for(int i  = 0; i<m; i++){
            cout<<answer[i]<<" ";
        }
        cout<<endl;
        return;
    }

    int index = -1;
    for(int i = 1; i<=n; i++){
        if(visited[i] == 0){
            index = i;
            break;
        }
    }
    cout<<2<<endl;
    debug(index);

    for(auto ele : edgelist){
        if(ele.first != index and ele.second != index){
            cout<<1<<" ";
        }

        else cout<<2<<" ";
    }

    cout<<endl;



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

