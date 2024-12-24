/**
 *    author: Saurav
 *    created: 2024.12.23 14:10:17
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
int bfs(int source, int sink , vector<int> &parent, vector<vector<int> > &adj , vector<vector<int> > &capacity){
    fill(parent.begin(),parent.end(),-1);
    parent[source] = -2;
    queue<pp> q;
    q.push({source,INT_MAX});

    while(!q.empty()){
        int currnode = q.front().first;
        int currmaxflow = q.front().second;
        q.pop();

        for(int nextnode : adj[currnode]){
            if(parent[nextnode] == -1 and capacity[currnode][nextnode]){
                parent[nextnode] = currnode;
                int newflow = min(currmaxflow,capacity[currnode][nextnode]);
                if(nextnode == sink){
                    return newflow;
                }
                q.push({nextnode,newflow});
            }
        }
    }

    return 0;
}

int maxflow(int source, int sink , vector<vector<int> > &adj , vector<vector<int> > &capacity, int n){
    int flow = 0;
    vector<int> parent(n+1);
    int newflow;

    while(newflow = bfs(source,sink,parent,adj,capacity)){
        flow += newflow;
        int currnode = sink;
        while(currnode != source){
            int prevnode = parent[currnode];
            capacity[prevnode][currnode] -= newflow;
            capacity[currnode][prevnode] += newflow;
            currnode = prevnode;
        }
    }

    return flow;
}
void solve(){
    int n,m;
    cin>>n>>m;

    int source = 1;
    int sink = n;

    vector<vector<int> > flowgraph (n+1,vector<int>(n+1,0));

    vector<vector<int> > adj (n+1,vector<int>());

    set<pp> edges;

    for(int i = 0; i<m; i++){
        int u,v,c;
        c = 1;
        cin>>u>>v;
        flowgraph[u][v] += c;
        flowgraph[v][u] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.insert({u,v});
        edges.insert({v,u});
    }

    int ans = maxflow(source,sink,adj,flowgraph,n);

    vector<int> parent(n+1, -1);

    bfs(source,sink,parent,adj,flowgraph);

    set<int> one;

    for(int i = 1;i<=n; i++){
        if(parent[i] != -1){
            one.insert(i);
        }
    }

    set<int> two;

    for(int i = 1; i<=n; i++){
        if(one.find(i) == one.end()){
            two.insert(i);
        }
    }

    int ans1 = 0;

    vector<pp> res;

    for(auto x : edges){
        int u = x.first;
        int v = x.second;
        if(one.find(u) != one.end() and two.find(v) != two.end()){
            ans1++;
            res.push_back({u,v});
        }
    }

    cout<<ans1<<endl;

    for(auto x : res){
        cout<<x.first<<" "<<x.second<<endl;
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

