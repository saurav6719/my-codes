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
    int kitnatimefuel;
    int remainingfuel;
    int currnode;
    bool operator<(const node &other) const {
        return kitnatimefuel > other.kitnatimefuel; // Min-heap based on dist (ascending order)
    }
};

int djikastra(vector<vector<pp> > &graph, int start, int end, int n, int capacity){

    vector<int> dist(n+1, 1e15);
    priority_queue<node> pq;
    pq.push({0, capacity, start});

    dist[start] = 0;

    while(!pq.empty()){
        auto front = pq.top();
        pq.pop();
        int currnode = front.currnode;
        int remainingfuel = front.remainingfuel;
        int kitnatimefuel = front.kitnatimefuel;

        if(dist[currnode] < kitnatimefuel) continue;
        // dist[currnode] = kitnatimefuel;

        for(auto neigh : graph[currnode]){
            int nextnode = neigh.first;
            int roadlenght = neigh.second;

            if(roadlenght > capacity) continue;

            if(remainingfuel >= roadlenght){
                if(dist[nextnode] >= kitnatimefuel){
                    dist[nextnode] = kitnatimefuel;
                    pq.push({dist[nextnode], remainingfuel - roadlenght, nextnode});
                }
            }
            else{
                // we need refueling 
                if(dist[nextnode] >= kitnatimefuel + 1){
                    dist[nextnode] = kitnatimefuel + 1;
                    pq.push({dist[nextnode], capacity - roadlenght, nextnode});
                }
            }
        }
    }

    if(dist[end] > 1e14) return -1;
    return dist[end];

}
void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int capacity ;
    cin>>capacity;

    vector<vector<pp> > graph(n+1, vector<pp> ());
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int start, end;
        cin>>start>>end;
        int ans = djikastra(graph, start, end, n, capacity);
        cout<<ans<<endl;
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

