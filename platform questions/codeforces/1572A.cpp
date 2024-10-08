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

int toposort(vector<vector<int> > &graph, int n, vector<int> &indegree, vector<int> &visited){
    priority_queue<int, vector<int> , greater<int> > pq;

    for(int i = 1; i<=n; i++){
        if(indegree[i] == 0){
            pq.push(i);
        }
    }

    int cnt = 1;

    priority_queue<int, vector<int>, greater<int> > pqnext;


    while(!pq.empty()){
        auto ff = pq.top();
        pq.pop();
        debug(ff);
        visited[ff] = 1;
        for(auto neigh : graph[ff]){
            indegree[neigh]--;
            debug(neigh);
            debug(indegree[neigh]);
            if(indegree[neigh] == 0){
                if(neigh < ff){
                    pqnext.push(neigh);
                }
                else pq.push(neigh);
            }
        }
        debug(pq.size());
        debug(pqnext.size());

        if(pq.empty() and !pqnext.empty()){
            pq = pqnext;
            while(!pqnext.empty()) pqnext.pop();
            cnt++;
        }
    }

    for(int i = 1; i<=n; i++){
        if(visited[i] == -1) return -1;
    }
    return cnt;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > graph(n+5, vector<int> ());
    vector<int> indegree(n+5);


    for(int i = 1; i<=n; i++){
        int k;
        cin>>k;
        for(int j = 0; j<k; j++){
            int ele;
            cin>>ele;
            graph[ele].push_back(i);
            indegree[i]++;
        }
    }

    print(indegree);

    vector<int> visited(n+5, -1);

    cout<<toposort(graph, n, indegree, visited)<<endl;



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

