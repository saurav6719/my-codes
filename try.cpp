/**
 *    author: Saurav
 *    created: 2024.11.21 14:40:36
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
int ans = 0;
vector<vector<int> > dp;
void f(vector<vector<int> > &graph, int node, int mask, int cnt){

    // is node pe aap is mask ke saath aaye ho aur cnt nodes le chuke ho 
    
    ans = max(ans, cnt);

    if(dp[node][mask] != -1){
        return;
    }

    dp[node][mask] = cnt;
    
    // take this node 
    mask |= (1<<node);
    for(auto neigh : graph[node]){
        if(mask & (1<<neigh)) continue;
        f(graph, neigh, mask, cnt+1);
    }

    ans = max(ans, cnt+1);


    return;
    
}
void solve(){
    int n;
    cin>>n;
    vector<pair<string, string > > input(n);
    map<string, set<int> > mpgenre;
    map<string, set<int> > mpactor;

    for(int i=0;i<n;i++){
        cin>>input[i].first>>input[i].second;
        mpgenre[input[i].first].insert(i);
        mpactor[input[i].second].insert(i);
    }

    

    vector<vector<int> > graph(n+1, vector<int> ());

    dp.assign(n+1, vector<int> ((1<<n), -1));

    for(int i= 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i==j) continue;
            string & s1 = input[i].first;
            string & s2 = input[i].second;
            string & s3 = input[j].first;
            string & s4 = input[j].second;
            if(mpgenre[s1].count(j) || mpgenre[s3].count(i) || mpactor[s2].count(j) || mpactor[s4].count(i)){
                graph[i].push_back(j);
            }
        }
    }

    

    ans = 0;


    for(int i=0;i<n;i++){
        f(graph, i, 0, 0);
    }

    debug(ans);

    cout<<n-ans<<endl;


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

