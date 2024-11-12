/**
 *    author: Saurav
 *    created: 2024.11.12 14:28:56
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
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> b(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    set<int> st;

    for(int i = 0; i<n; i++){
            st.insert(i);
    }

    queue<pp> q;

    vector<int> dist(n+1, 1e18);
    dist[n] = 0;

    vector<int> parent(n+1);
    parent[n] = -1;

    q.push({n,n});

    // x,y -> currently i am at x and i slipped from y 

    while(!q.empty()){
        int currpos = q.front().first;
        int prevrest = q.front().second;
        q.pop();

        int jump = currpos - a[currpos];

        if(jump <= 0){
            if(dist[0] > 1e17){
                dist[0] = dist[currpos] + 1;
                parent[0] = prevrest;
            }
        }

        auto it = st.lower_bound(jump);

        while(it != st.end() and *it < currpos){
            int temp = *it + b[*it];

            if(dist[temp] > 1e17){
                dist[temp] = dist[currpos] + 1;
                q.push({temp,*it});
            }

            parent[*it] = prevrest;
            st.erase(it);
            it = st.lower_bound(jump);

        }
    }

    if(dist[0] == 1e18){
        cout<<-1<<endl;

        return;
    }

    cout<<dist[0]<<endl;

    vector<int> path;

    for(int i = 0; i != n; i = parent[i]){
        path.push_back(i);
    }

    reverse(path.begin(), path.end());

    for(auto x : path){
        cout<<x<<" ";
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

