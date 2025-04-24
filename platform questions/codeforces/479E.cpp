/**
 *    author: Saurav
 *    created: 2024.10.25 23:12:27
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

int f(vector<int> &prf , int x , int lb, int up , int inputx){

    if(x==4){
        debug(lb);
        debug(up);
    }

    print(prf);
    int n = prf.size();
    n--;
    if(lb < 1) lb = 1;
    if(up > n) up = n;
    int xx = prf[up];
    int yy = prf[lb-1];
    xx %= mod;
    yy %= mod;
    xx = (xx - yy + mod) % mod;
    xx -= inputx;
    xx += mod;
    xx %= mod;  
    return max(0ll , xx);

    
}
void solve(){
    int n,a,b,k;
    cin>>n>>a>>b>>k;

    vector<int> prev(n+1,1);
    prev[0] = 0;

    for(int i = 1; i<=k; i++){
        debug(i);
        print(prev);
        int m  = prev.size();
        vector<int> prfsum(m,0);
        prfsum[0] = prev[0];

        for(int i = 1; i<m; i++){
            prfsum[i] = prfsum[i-1] + prev[i];
            prfsum[i] %= mod;
        }

        vector<int> next(n+1, 0);
        for(int x = 1; x<=n; x++){
            int aa = abs(x - b);
            if(aa <= 1){
                next[x] = 0;
                continue;
            }
            next[x] = f(prfsum , x, x - (aa -1), x+(aa-1), prev[x]);
            next[x] %= mod;
        }
        prev = next;
    }
    print(prev);

    cout<<prev[a] % mod<<endl;
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

