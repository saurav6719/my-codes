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
    int n ;
    cin>>n;
    int k;
    cin>>k;

    vector<vector<int> > tree(n+5, vector<int> ());

    for(int i = 0; i< n-1; i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    if(n==1){
        cout<<0<<endl;
        return;
    }

    set<int> one;
    vector<int> degree(n+5, 0);


    for(int i = 1; i<=n; i++){
        degree[i] = tree[i].size();
        if(degree[i] == 1){
            one.insert(i);
        }
    }
    print(degree);

    int cnt = 0;
    int less = 0;
    while(cnt<n and k>0 and less<10){
        k--;
        debug(k);
        set<int>newone;
        for(auto ele : one){
            debug(ele);
            
            if(degree[ele] == 0) {
                cnt++;
                continue;
            }

            degree[ele] = 0;
            cnt++;
            for(auto ele2 : tree[ele]){
                if(degree[ele2] == 0) continue;
                degree[ele2]--;
                if(degree[ele2] == 1){
                    newone.insert(ele2);
                }
                if(degree[ele2] == 0 and one.count(ele2) == 0){
                    degree[ele2] = 1;
                }
                
            }
        }
        one = newone;
        print(degree);
        
    }

    int ans = 0;

    for(int i = 1; i<=n; i++){
        if(degree[i] > 0) ans++;
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
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

