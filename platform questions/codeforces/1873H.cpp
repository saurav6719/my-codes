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

bool dfs(vector<vector<int> >&graph, vector<int> &visited, set<int> &cyclenode,int node, int par, vector<int> &parent){
    visited[node] = 1;
    parent[node] = par;

    debug(node);
    debug(par);

    for(auto child : graph[node]){
        if(cyclenode.count(child)) continue;
        if(visited[child] == 0){
            bool xx = dfs(graph, visited, cyclenode, child, node, parent);
            if(xx) return true;
        }

        else if(visited[child] == 1 and child != par){
            //cycle found
            int first = node;
            while (first != child) {
                cyclenode.insert(first);
                first = parent[first];
            }
            debug(node);
            debug(child);
            cyclenode.insert(child);
            return true;
        }
    }
    return false;
}
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<int> > graph(n+5, vector<int>());

    for(int i = 0; i<n; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n+5, 0);
    set<int> cyclenodes;
    vector<int> parent(n+5, 0);
    for(int i = 1; i<=n; i++){
        if(visited[i] == 0){
            bool xx = dfs(graph, visited, cyclenodes, i,0,parent);
            if(xx) break;
        }
    }

    // for(auto ele : cyclenodes){
    //     cout<<ele<<" ";
    // }
    // cout<<endl;


    vector<int> dista(n+5, 1e10);
    vector<int> distb(n+5, 1e10);

    priority_queue<pp, vector<pp> , greater<pp> > pqa;
    pqa.push({0, a});

    dista[a] = 0;

    while(!pqa.empty()){
        pp ff = pqa.top();
        int currnode = ff.second;
        int currdist = ff.first;

        pqa.pop();

        if(dista[currnode] < currdist) continue;

        for(auto neigh : graph[currnode]){
            int newdist = currdist+1;
            if(dista[neigh] > newdist){
                dista[neigh] = newdist;
                pqa.push({newdist, neigh});
            }
        }
    }


    priority_queue<pp, vector<pp> , greater<pp> > pqb;
    pqb.push({0, b});

    distb[b] = 0;

    while(!pqb.empty()){
        pp ff = pqb.top();
        int currnode = ff.second;
        int currdist = ff.first;

        pqb.pop();

        if(distb[currnode] < currdist) continue;

        for(auto neigh : graph[currnode]){
            int newdist = currdist+1;
            if(distb[neigh] > newdist){
                distb[neigh] = newdist;
                pqb.push({newdist, neigh});
            }
        }
    }

    print(dista);
    print(distb);


    for(auto ele : cyclenodes){
        if(distb[ele] < dista[ele]){
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

