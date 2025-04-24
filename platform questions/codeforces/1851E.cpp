
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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
vector<int> dp;
int dfs(int i, vector<vector<int>> &mixing, set<int> &st, vector<int> &cost){
    if(st.count(i)) return dp[i] = 0; // If i is in the set, return 0 cost
    if(dp[i] != -1) return dp[i]; // If dp[i] is already computed, return its value

    int res1 = cost[i]; // cost of not mixing
    int res2 = 0; // cost of mixing
    if(mixing[i].empty()) res2 = INT_MAX; // If no mixing options, set res2 to max value

    for(int j = 0; j < mixing[i].size(); j++){
        res2 += dfs(mixing[i][j], mixing, st, cost); // Recursive call
    }

    return dp[i] = min(res1, res2); // Store the result in dp and return the minimum of both strategies
}

void solve(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> input(n+1);
    for(int i = 1; i <= n; i++){
        cin >> input[i];
    }
    dp.clear();
    dp.resize(n+5, -1);
    set<int> st;
    for(int i = 0; i < k; i++){
        int ele;
        cin >> ele;
        st.insert(ele);
    }

    vector<vector<int>> mixing(n+1);
    for(int i = 1; i <= n; i++){
        int sz;
        cin >> sz;
        for(int j = 0; j < sz; j++){
            int ele;
            cin >> ele;
            mixing[i].push_back(ele);
        }
    }

    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++){
        ans[i] = dfs(i, mixing, st, input); // Compute the result for each i
    }

    // Print the results
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}