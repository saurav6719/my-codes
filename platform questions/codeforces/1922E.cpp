/**
 *    author: Saurav
 *    created: 2024.10.17 02:12:40
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
int floor_log2(unsigned long long x){
    if(x == 0){
        throw invalid_argument("Undefined for x = 0");
    }
    int log = 0;
    while(x >>= 1){
        log++;
    }
    return log;
}

void solve(){
    int x;
    cin>>x;

    vector<int> ans;

    int xx = floor_log2(x) ;
    debug(xx);
    for(int i = 1; i<=xx ; i++){
        ans.push_back(i) ;
    }
    x-= (1ll<<xx) ;

    debug(x);
    
    print(ans);

    int cnt = 0;

    while(x>0){
        int xxy = floor_log2(x);
        debug(xxy);
        ans.push_back(xxy+1);
        debug(x);
        // debug(1ll<<xxy);
        int zz = 1ll<<xxy;
        debug(zz);
        x -= zz;
        debug(x);
        cnt ++ ;
    }

    cout<<ans.size()<<endl;
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
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
