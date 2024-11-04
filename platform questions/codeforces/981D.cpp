/**
 *    author: Saurav
 *    created: 2024.11.04 08:05:47
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

int dp[55][55][55];
int f(int i, int j,int k,  vector<int> &input){
    // dp[i][j][k] = required value from i to j if i have to make k partitions

    if(k==0){
        return input[j] - (i>0 ? input[i-1] : 0);
    }

    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }

    if(i>=j){
        return 0;
    }

    int ans = -1e18;

    for(int x = i; x<j; x++){
        ans = max(ans, f(x+1,j,k-1, input) & (input[x] - (i>0 ? input[i-1] : 0)));
    }

    return dp[i][j][k] = ans;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> input(n);
    for(int i = 0; i<n;i++){
        cin>>input[i];
    }

    memset(dp, -1, sizeof(dp));

    for(int i = 1; i<n; i++){
        input[i] += input[i-1];
    }

    cout<<f(0,n-1,k-1, input);
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

