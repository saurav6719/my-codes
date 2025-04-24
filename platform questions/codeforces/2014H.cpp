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
void generate_test_case(int n = 100000, int m = 100000, int h = 1000, int max_weight = 100) {
    srand(time(0)); // Initialize random seed
    
    vector<pair<pair<int, int>, int>> edges; // To store the edges (u, v, weight)
    set<pair<int, int>> edge_set; // To avoid duplicate edges

    // Step 1: Ensure the graph is connected (we create a spanning tree first)
    for (int i = 2; i <= n; ++i) {
        int u = rand() % (i - 1) + 1; // Randomly connect to a previous node to form a tree
        int v = i;
        int w = rand() % max_weight + 1; // Random weight between 1 and max_weight
        edges.push_back({{u, v}, w});
        edge_set.insert({min(u, v), max(u, v)}); // To avoid duplicates
    }

    // Step 2: Add remaining edges to reach exactly m edges
    while (edges.size() < m) {
        int u = rand() % n + 1;
        int v = rand() % n + 1;
        if (u == v || edge_set.count({min(u, v), max(u, v)})) continue; // Skip self-loops and duplicates
        int w = rand() % max_weight + 1; // Random weight
        edges.push_back({{u, v}, w});
        edge_set.insert({min(u, v), max(u, v)});
    }

    // Step 3: Generate h special vertices
    vector<int> special_vertices;
    while (special_vertices.size() < h) {
        int vertex = rand() % n + 1;
        if (find(special_vertices.begin(), special_vertices.end(), vertex) == special_vertices.end()) {
            special_vertices.push_back(vertex);
        }
    }

    // Output the test case
    cout << n << " " << m << endl; // Number of vertices and edges
    cout << h << endl; // Number of special vertices
    for (int v : special_vertices) {
        cout << v << " ";
    }
    cout << endl;

    for (auto &edge : edges) {
        cout << edge.first.first << " " << edge.first.second << " " << edge.second << endl;
    }

    
}

struct xx{
    int dest;
    int dist;
    int horse;
    bool operator<(const xx& other) const {
        return dist > other.dist;  // This ensures that the priority_queue behaves like a min-heap
    }
};
void solve(){
    int n,m,h;
    cin>>n>>m>>h;
    set<int>horses;

    for(int i = 0 ;i<h; i++){
        int ele;
        cin>>ele;
        horses.insert(ele);
    }

    vector<vector<pp> > graph(n+5, vector<pp> ());
    for(int i = 0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    vector<int> distf1(n+5, 1e15);

    priority_queue<xx, vector<xx>> pq;  // Removed std::greater<xx>

    pq.push(xx{1, 0, (horses.count(1) ? 1 : 0)});

    distf1[1] = 0;

    map<int,int> hashoorse;

    if(horses.count(1)){
        hashoorse[1] = 0;
    }

    while(!pq.empty()){
        xx ff = pq.top();
        pq.pop();
        int currnode = ff.dest;
        int currlen = ff.dist;
        int hashorse = ff.horse;

        if(distf1[currnode] < currlen and hashorse == 0) continue;

        for(auto neigh : graph[currnode]){
            if(distf1[neigh.first] > currlen + (hashorse ? (neigh.second/2) : (neigh.second))){
                distf1[neigh.first] = currlen + (hashorse ? (neigh.second/2) : (neigh.second));
                pq.push(xx{neigh.first, currlen + (hashorse ? (neigh.second/2) : (neigh.second)), (hashorse ? (1) : (horses.count(neigh.first) ? 1 : 0))});
                if(hashorse == 1 or horses.count(neigh.first)){
                    if(hashoorse.count(neigh.first)){
                        hashoorse[neigh.first] = min(hashoorse[neigh.first] , distf1[neigh.first]);
                    }
                }
            }
            else if(hashoorse.count(neigh.first) and hashoorse[neigh.first] <= currlen + (hashorse ? (neigh.second/2) : (neigh.second)))continue;
            else if(hashorse or horses.count(neigh.first)){
                pq.push(xx{neigh.first, currlen + (hashorse ? (neigh.second/2) : (neigh.second)), (hashorse ? (1) : (horses.count(neigh.first) ? 1 : 0))});
                hashoorse[neigh.first] = currlen + (hashorse ? (neigh.second/2) : (neigh.second));
            } 
        }
    }

    print(distf1);

    vector<int> distfn(n+5, 1e15);

    priority_queue<xx, vector<xx>> pqn;  // Removed std::greater<xx>

    pqn.push(xx{n, 0, (horses.count(n) ? 1 : 0)});

    distfn[n] = 0;

    map<int,int> hashoorsen;

    if(horses.count(1)){
        hashoorsen[n] = 0;
    }

    while(!pqn.empty()){
        xx ff = pqn.top();
        pqn.pop();
        int currnode = ff.dest;
        int currlen = ff.dist;
        int hashorse = ff.horse;

        if(distfn[currnode] < currlen and hashorse == 0) continue;

        for(auto neigh : graph[currnode]){
            if(distfn[neigh.first] > currlen + (hashorse ? (neigh.second/2) : (neigh.second))){
                distfn[neigh.first] = currlen + (hashorse ? (neigh.second/2) : (neigh.second));
                pqn.push(xx{neigh.first, currlen + (hashorse ? (neigh.second/2) : (neigh.second)), (hashorse ? (1) : (horses.count(neigh.first) ? 1 : 0))});
            }

            else if(hashoorsen.count(neigh.first) and hashoorsen[neigh.first] <= currlen + (hashorse ? (neigh.second/2) : (neigh.second)))continue;
            else if(hashorse or horses.count(neigh.first)){
                pqn.push(xx{neigh.first, currlen + (hashorse ? (neigh.second/2) : (neigh.second)), (hashorse ? (1) : (horses.count(neigh.first) ? 1 : 0))});
                hashoorsen[neigh.first] = currlen + (hashorse ? (neigh.second/2) : (neigh.second));
            } 
        }
    }

    print(distfn);


    int mini = INT_MAX;

    for(int i = 1;i<=n; i++){
        int x = distf1[i];
        int y = distfn[i];

        mini = min(mini, max(x,y));
    }

    if(mini > 1e9) mini = -1;

    cout<<mini<<endl;










}
/* logic ends */

signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    stringstream input;
    // generate_test_case();
    int t;
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
 