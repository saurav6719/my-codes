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
void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int> > graph(n+5, vector<int> ());

    vector<vector<int> > revgraph(n+5, vector<int> ());

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        revgraph[v].push_back(u);
    }

    int k;
    cin>>k;
    vector<int> path(k);
    for(int i = 0; i<k; i++){
        cin>>path[i];
    }

    int dest = path.back();

    priority_queue<pp,vector<pp> , greater<pp> >pq;

    vector<int> dis(n+5, 1e10);
    dis[dest] = 0;

    vector<int> number(n+5, 0);

    number[dest] = 1;

    pq.push({0, dest});
    vector<int> visited(n+5, 0);
    while(!pq.empty()){
        
        pp ff = pq.top();
        int currdist = ff.first;
        int currnode = ff.second;
        debug(currnode);
        debug(number[currnode]);
        pq.pop();
        if(dis[currnode] < currdist) {
            cout<<"YES"<<endl;
            debug(currnode);
            continue;
        }
        for(auto parent : revgraph[currnode]){
            debug(parent);
            int currshortestdist = currdist + 1;
            if(dis[parent] > currshortestdist){
                dis[parent] = currshortestdist;
                number[parent] = 1;
                debug(number[parent]);
                pq.push({currshortestdist , parent});
            }

            else if(dis[parent] == currshortestdist){
                number[parent]++;
            }
        }
    }

    print(dis);
    print(number);


    int mini = 0;
    for(int i = 0; i<k-1; i++){
        int currele = path[i];
        int aglaele = path[i+1];
        int aapkashorteslength = dis[currele];
        int aglashortestlength = dis[aglaele];
        if(aapkashorteslength == aglashortestlength + 1) continue;
        else mini++;
    }

    int maxi = 0;
    for(int i = 0; i<k-1; i++){
        int currele = path[i];
        int aglaele = path[i+1];
        int aapkashortestlength = dis[currele];
        int aglashortestlength = dis[aglaele];
        if(aapkashortestlength != aglashortestlength+1) maxi++;
        else{
            if(aapkashortestlength == aglashortestlength+1 and number[currele] > 1) maxi++;
        }
    }

    cout<<mini<<" "<<maxi;

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

