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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > graph(n+5, vector<int> ());
    vector<vector<int> > edgelist(m, vector<int> (3));
    for(int i = 0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edgelist[i][0] = u;
        edgelist[i][1] = v;
        edgelist[i][2] = -1*w;

        graph[v].push_back(u);
    }

    vector<int> dist(n+5, 1e15);
    dist[1] = 0;

    for(int i = 0; i<=m-1; i++){
        for(int j = 0; j<m; j++){
            int u = edgelist[j][0];
            int v = edgelist[j][1];
            int w = edgelist[j][2];
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    vector<int> dis_copy = dist;
    //print(dis_copy);

    int val1 = dist[n];
    debug(val1);
    
    for(int i = 0; i<= m-1; i++){
        for(int j = 0; j<m; j++){
        int u = edgelist[j][0];
        int v = edgelist[j][1];
        int w = edgelist[j][2];
        if(dist[u] + w < dist[v]){
            dist[v] = dist[u] + w;
        }
        }
    }

    print(dist);

    //print(dist);

    vector<int> num(n+5, -1);
    for(int i = 0; i<n+5; i++){
        if(dist[i] != dis_copy[i]){
            num[i] = 1;
        }
    }

    set<int> st;
    queue<int> qu;
    qu.push(n);
    vector<int> vissi(n+5, -1);
    vissi[n] = 1;
    while(!qu.empty()){
        int ff = qu.front();
        qu.pop();
        for(auto neigh : graph[ff]){
            if(vissi[neigh] == -1){
                qu.push(neigh);
                st.insert(neigh);
                vissi[neigh] = 1;
            }
        }
    }


    for(auto ele : st){
        debug(ele);
        if(num[ele] == 1 and dist[ele] < 1e11){
            cout<<-1;
            return;
        }
    }


    int val2 = dist[n];
    debug(val2);

    for(int i = 0 ; i<n+5; i++){
        if(val1 != val2){
            cout<<-1;
            return;
        }
    }

    

    cout<<-1 * val1;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

