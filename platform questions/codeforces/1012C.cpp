/**
 *    author: Saurav
 *    created: 2024.11.04 23:35:58
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
int dp[5005][5005][2];
int f(int i, int k, bool lastupdated, vector<int> &v){
    int n = v.size();

    if(k==0)    return 0;

    if(i>=n)    return 1e9;

    if(dp[i][k][lastupdated] != -1) return dp[i][k][lastupdated];

    // take 
    int cost = 0;
    if(i>0 and lastupdated == false) {
        cost += max(0LL, v[i-1] - v[i] + 1);
    }

    if(i > 0 and lastupdated == true){
        int prev = min(v[i-1] , v[i-2] - 1);
        cost += max(0LL, prev - v[i] + 1);
    }
    if(i < n-1){
        cost += max(0LL, v[i+1] - v[i] + 1);
    }

    int take = cost + f(i+2, k-1, true, v);

    // not take 

    int not_take = f(i+1, k, false, v);

    return dp[i][k][lastupdated] = min(take, not_take);
}
void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }   

    memset(dp, -1, sizeof dp);

    

    for(int l = 1; l<= (n/2 + n%2); l++){
        cout<<f(0, l, false, v)<<" ";
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

