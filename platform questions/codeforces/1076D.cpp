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


void toposort(vector<vector<int>> &graph, vector<int> &indegree , int n, map<pp,int> &mp, vector<int> &order, vector<int> &last){
    queue<int> qu;

    for(int i = 1; i<=n; i++){
        if(indegree[i] == 0){
            debug(i);
            qu.push(i);
        }
    }

    while(!qu.empty()){
        auto ff = qu.front();
        qu.pop();
        int u = ff;
        int v = last[u];
        if(u==0 or v==0) continue;
        pp xx = {u,v};
        for(auto ele : graph[u]){
            indegree[ele]--;
            if(indegree[ele] == 0) qu.push(ele);
        }
        debug(u);
        debug(v);
        int z = mp[xx];
        debug(z);
        order.push_back(z);
    }
}
void dijkastra(vector<vector<pp> > &graph, vector<int> &dist, vector<int> &last){
    priority_queue<pp, vector<pp> , greater<pp> > pq;

    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        auto ff = pq.top();
        pq.pop();
        int currnode = ff.second;
        int currweight = ff.first;

        if(dist[currnode] < currweight){
            continue;
        }

        for(auto neigh : graph[currnode]){
            if(currweight + neigh.second < dist[neigh.first]){
                dist[neigh.first] = currweight + neigh.second;
                last[neigh.first] = currnode;
                pq.push({currweight + neigh.second , neigh.first});
            }
        }
    }

}
void solve(){


    int n,m,k;
    cin>>n>>m>>k;

    map<pp, int> mp;
    vector<vector<pp> > graph(n+5, vector<pp> ());

    for(int i = 0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
        mp[{u,v}] = i+1;
        mp[{v,u}] = i+1;
    }

    vector<int> dist(n+5, 1e15);
    vector<int> last(n+5, 0);

    dijkastra(graph, dist, last);

    print(last);
    

    set<int> st;

    for(int i = 1; i<=n; i++){
        int u = i;
        int v = last[i];

        pp one = {u,v};
        if(mp.count(one)){
            st.insert(mp[one]);
        }
    }

    set<int> removed;
    for(int i = 1; i<=m; i++){
        if(st.count(i) == 0){
            removed.insert(i);
        }
    }

    // for(auto ele : removed){
    //     cout<<ele<<" ";
    // }

    vector<int> order;
    for(auto ele : removed){
        order.push_back(ele);
    }
    


    vector<vector<int> > newgraph(n+5, vector<int> ());

    vector<int> indegree(n+5, 0);

    for(int i = 2; i<=n; i++){
        int xx = last[i];
        newgraph[i].push_back(xx);
        indegree[xx]++;
    }

    print(indegree);

    print2d(newgraph);

    int toremove = m - k;
    print(order);

    toposort(newgraph, indegree , n, mp, order, last);
    

    print(order);

    cout<<k<<endl;

    for(int i = m-k; i<m; i++){
        cout<<order[i]<<" ";
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

