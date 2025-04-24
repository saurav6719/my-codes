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
int f(int n){
    if(n < 50) return 97;
    return 1000000007;
}
void solve(){
    int n,m;
    cin>>n>>m;

    if(m==1){
        cout<<2<<" "<<2<<endl;
        cout<<1<<" "<<2<<" "<<2<<endl;
        return;
    }
    vector<vector<pp> > graph(n+1, vector<pp> ());

    for(int i = 2; i<=n; i++){
        graph[1].push_back({i, 2});
    }

    int sum = 2 * (n-2);
    // debug(sum);

    int nextprime = f(sum);

    int last = nextprime - sum;
    // debug(last);

    

    graph[1][0].second = last;

    m-= (n-1);

    debug(m);

    int cnt = 0;
    bool done = false;
    for(int i =2; i<=n; i++){
        if(cnt>=m) break;
        for(int j = i+1; j<=n; j++){
            if(cnt >= m) break;
            graph[i].push_back({j, 1000000000});
            cnt++;
            if(cnt >= m){
                done = true;
                break;
            }
        }
        if(cnt >= m) break;
        if(done) break;
    }

    

    cout<<2<<" "<<nextprime<<endl;

    for(int i = 1; i<=n; i++){
        for( auto ele : graph[i]){
            cout<<i<<" "<<ele.first<<" "<<ele.second<<endl;
        }
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

