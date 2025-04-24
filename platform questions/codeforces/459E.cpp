/**
 *    author: Saurav
 *    created: 2024.10.25 20:46:12
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

struct edge{
    int u,v,wt;
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<edge> edgelist;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        edgelist.push_back({a,b,c});
    }

    sort(edgelist.begin(),edgelist.end(),[](edge a, edge b){
        return a.wt < b.wt;
    });

    vector<int> dp(n+1, 0);

    int i = 0;
    int sz = edgelist.size();

    while(i < m){
        int j = i;
        int j_copy = i;
        map<int,int> mp;
        while(j < sz and edgelist[j].wt == edgelist[i].wt){
            j ++ ;

            mp[edgelist[j-1].u] = dp[edgelist[j-1].u];
            mp[edgelist[j-1].v] = dp[edgelist[j-1].v];
        }

        
        while(j_copy < j){
            int u = edgelist[j_copy].u;
            int v = edgelist[j_copy].v;

            if(mp.count(v)){
                dp[v] = max(dp[v], mp[u] + 1);
            }
            else dp[v] = max(dp[v], dp[u] + 1);
            j_copy ++ ;
        }
        i = j;
    }

    int ans = 0;

    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
    }

    cout<<ans<<endl;



    


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

