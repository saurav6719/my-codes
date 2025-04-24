/**
 *    author: Saurav
 *    created: 2024.10.26 22:59:31
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
int dp[501][501];
int f(int i, int j , vector<int> &arr){
    if(i>j) return 0;
    if(i==j) return 1;
    if(j-i == 1 and arr[i] == arr[j]) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = 1e15;
    ans = min(ans , f(i+1, j, arr) + 1);
    if(arr[i] == arr[j]){
        ans = min(ans , f(i+1, j-1, arr));
    }
    for(int k = i+1; k<j; k++){
        if(arr[i] == arr[k]){
            ans = min(ans , f(i, k, arr) + f(k+1, j, arr));
        }
    }
    return dp[i][j] = ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0 ; i<n; i++){
        cin>>input[i];
    }
    memset(dp, -1, sizeof dp);
    cout<<f(0,n-1, input);
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

