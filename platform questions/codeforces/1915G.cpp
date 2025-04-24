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
struct node{
    int value;
    int dist;
    int slowness;
    bool operator<(const node &other) const {
        return dist > other.dist; // Min-heap based on dist (ascending order)
    }
};
int dijkastra(vector<vector<pp> > &graph, vector<int> &slowness,int n){
    vector<int> dist(n+1, INT_MAX);
    vector<int> currslowness(n+1, INT_MAX);
    dist[1] = 0;
    currslowness[1] = slowness[1];

    vector<vector<int> > dp(n+1, vector<int> (1001, INT_MAX));

    priority_queue<node> pq;

    for(auto ele : graph[1]){
        int u = ele.first;
        int w = ele.second;
        dist[u] = w * slowness[1];
        currslowness[u] = slowness[1];
        pq.push({u, dist[u], currslowness[u]});

        dp[u][slowness[1]] = dist[u];

        // debug(u);
        // debug(dist[u]);
        // debug(currslowness[u]);
    }

    int cnt = 0;

    while(!pq.empty()){
        cnt++;
        node curr = pq.top();
        pq.pop();

        int currnode = curr.value;
        int currdist = curr.dist;
        int currslow = curr.slowness;

        debug(currnode);
        debug(currdist);
        debug(currslow);

        if(dist[currnode] < currdist and currslowness[currnode] <= currslow)  {
            // cout<<"currnode is "<<currnode<<endl;
            // cout<<"currdist is "<<currdist<<endl;
            // cout<<"currslow is "<<currslow<<endl;
            continue;
        }

        for(auto ele : graph[curr.value]){
            int u = ele.first;
            int w = ele.second;
            // debug(u);
            // debug(w);

            int newdist;
            int newslowness;

            // debug(newdist);
            // debug(newslowness);

            if(currslow < slowness[currnode]){

                // not take 
                newdist = curr.dist + w * currslow;
                newslowness = currslow;
                if(newdist >= dist[u] and newslowness >= currslowness[u]) {

                }
                else{
                    if(dp[u][newslowness] <= newdist) continue;
                    if(newdist <= dist[u]){

                        dist[u] = newdist;
                        currslowness[u] = newslowness;
                        pq.push({u, dist[u], currslowness[u]});
                        dp[u][newslowness] = min(dp[u][newslowness], newdist);
                    }
                    else if(newdist == dist[u]){
                        currslowness[u] = min(currslowness[u], newslowness);
                        pq.push({u, dist[u], currslowness[u]});
                        dp[u][newslowness] = min(dp[u][newslowness], newdist);

                    }
                    else{
                        pq.push({u, newdist, newslowness});
                        dp[u][newslowness] = min(dp[u][newslowness], newdist);

                    }
                }
            }

            else{
                //take 
                newdist = curr.dist + w * slowness[currnode];
                newslowness = slowness[currnode];
                // debug(newdist);
                // debug(newslowness);

                if(newdist >= dist[u] and newslowness >= currslowness[u]){

                }
                else{
                    if(dp[u][newslowness] <= newdist) continue;

                    if(newdist < dist[u]){
                        dist[u] = newdist;
                        currslowness[u] = newslowness;
                        pq.push({u, dist[u], currslowness[u]});
                        dp[u][newslowness] = min(dp[u][newslowness], newdist);

                    }
                    else if(newdist == dist[u]){
                        currslowness[u] = min(currslowness[u], newslowness);
                        pq.push({u, dist[u], currslowness[u]});
                        dp[u][newslowness] = min(dp[u][newslowness], newdist);

                    }
                    else{
                        pq.push({u, newdist, newslowness});
                        dp[u][newslowness] = min(dp[u][newslowness], newdist);

                    }
                }
            }
        }
    }

    return dist[n];
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pp> > graph(n+1, vector<pp> ());

    for(int i = 0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    vector<int> slowness(n+1);

    for(int i=1; i<=n; i++){
        cin>>slowness[i];
    }

    int xx = dijkastra(graph, slowness, n);
    cout<<xx<<endl;
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

