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

void solve(){
    // ans = -1;
    int n,m;
    cin>>n>>m;

    vector<vector<pp> > graph(n+5, vector<pp> ());

    for(int i= 0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }


    vector<vector<int> > times(n+5,vector<int> ());

    for(int i = 1; i<=n; i++){
        int k;
        cin>>k;
        for(int j = 0;j<k; j++){
            int time;
            cin>>time;
            times[i].push_back(time);
        }
    }
    int start = 1;
    int starttime = 0;
    for(int i = 0; i<times[start].size();i++){
        if(times[start][i] == starttime) starttime++;
    }

    priority_queue<pp, vector<pp> , greater<pp> >pq; 

    vector<int> dist(n+5, 1e10);

    dist[start] = 0;

    pq.push({0, 1});

    debug(starttime);
    debug(start);
    int cnt = 0;
    while(!pq.empty()){
        // cnt++;
        pp ff = pq.top();
        pq.pop();

        int currnode = ff.second;
        int currdist = ff.first;

        debug(currnode);
        debug(currdist);

        int newniklnetime = currdist;


        for(int i = 0; i<times[currnode].size();i++){
            if(times[currnode][i] == newniklnetime) newniklnetime++;
        }

        debug(newniklnetime);




        if(dist[currnode] < currdist)continue;

        for(auto neigh : graph[currnode]){
            int newdist = newniklnetime + neigh.second;
            debug(neigh.first);
            debug(neigh.second);;
            debug(newdist);
            if(dist[neigh.first] > newdist){
                dist[neigh.first ] = newdist;
                pq.push({newdist, neigh.first});
            }
        }
    }



    if(dist[n] > 1e10 -50) dist[n] = -1;
    cout<<dist[n];





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

