/**
 *    author: Saurav
 *    created: 2024.12.24 15:38:03
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
class MaxFlow {
private:
    int n; // Number of nodes
    int source, sink; // Source and sink nodes
    vector<vector<int>> &capacity; // Capacity matrix
    vector<vector<int>> adj; // Adjacency list
 
    // Helper function to perform BFS
    int bfs(vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2; // Mark the source as visited
        queue<pair<int, int>> q; // Queue to store (node, flow)
        q.push({source, INT_MAX});
 
        while (!q.empty()) {
            int curr = q.front().first;
            int flow = q.front().second;
            q.pop();
 
            for (int next : adj[curr]) {
                if (parent[next] == -1 && capacity[curr][next] > 0) {
                    parent[next] = curr;
                    int new_flow = min(flow, capacity[curr][next]);
                    if (next == sink)
                        return new_flow; // Found a path to the sink
                    q.push({next, new_flow});
                }
            }
        }
        return 0; // No more augmenting paths
    }

public:
    // Constructor
    MaxFlow(int nodes, int sourceNode, int sinkNode, vector<vector<int>>& cap)
        : n(nodes), source(sourceNode), sink(sinkNode), capacity(cap) {
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (capacity[i][j] > 0) {
                    adj[i].push_back(j);
                    adj[j].push_back(i); // Add reverse edge for residual graph
                }
            }
        }
    }
 
    // Function to calculate the maximum flow
    int getMaxFlow() {
        int totalFlow = 0;
        vector<int> parent(n);
 
        int new_flow;
        while (new_flow = bfs(parent)) {
            totalFlow += new_flow;
            int curr = sink;
 
            // Update the residual capacities
            while (curr != source) {
                int prev = parent[curr];
                capacity[prev][curr] -= new_flow;
                capacity[curr][prev] += new_flow;
                curr = prev;
            }
        }
 
        return totalFlow;
    }
};


bool bfs2(int source, int sink, vector<vector<int> > &flowing, vector<vector<int> > adj, vector<int> &parent){
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto next : adj[curr]){
            if(parent[next] == -1 && flowing[curr][next] == 1){
                parent[next] = curr;
                if(next == sink){
                    return true;
                }
                q.push(next);
            }
        }
    }
    return false;
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> flowgraph(n+5, vector<int>(n+5, 0));

    vector<vector<int>> adj(n+5);

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b;
        c = 1;
        adj[a].push_back(b);
        flowgraph[a][b] = c;
    }

    vector<vector<int> > initial = flowgraph;

    int source = 1, sink = n;

    MaxFlow mf(n+5, source, sink, flowgraph);

    int maxflow = mf.getMaxFlow();

    vector<vector<int> > residual = flowgraph;


    vector<vector<int> > flowing(n+5, vector<int>(n+5, 0));

    for(int i = 1; i<=n; i++){
        for(auto x : adj[i]){
            if(residual[i][x] == 0){
                flowing[i][x] = 1;
            }
        }
    }

    vector<int> parent(n+5);

    vector<vector<int>> ans;

    while(bfs2(source, sink, flowing, adj, parent)){
        vector<int> res;
        int curr = sink;
        while(curr != source){
            res.push_back(curr);
            int prev = parent[curr];
            flowing[prev][curr] = 0;
            curr = prev;
        }
        res.push_back(source);

        reverse(res.begin(), res.end());

        ans.push_back(res);


    }


    if(ans.size() == 0){
        cout<<0<<endl;
        return;
    }

    cout<<ans.size()<<endl;

    for(auto x : ans){
        cout<<x.size()<<endl;
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return;

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

