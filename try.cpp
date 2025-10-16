/**
 *    author: Saurav
 *    created: 2025.10.17 05:05:18
 *    We stop at Candidate Master in 2025
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

#define printset(s) do { \
    cout << "set-- starts" << endl; \
    for (auto it = s.begin(); it != s.end(); ++it) { \
        cout << *it << endl; \
    } \
    cout << "set-- ends" << endl; \
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
#define printset(s)
#endif
#define endl "\n"
#define MOD 1000000007
#define mod_add(a, b) (((a) % MOD + (b) % MOD) % MOD)
#define mod_sub(a, b) ((((a) % MOD - (b) % MOD) + MOD) % MOD)
#define mod_mul(a, b) (((1LL * (a) % MOD) * (b) % MOD) % MOD)
#define int long long int
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void f(vector<vector<int> > &dp, int n, int chahi, vector<int> &ans, int i){
    if(i == 0) return ;
    // dekho yaha pe kya liya hoga
    for(int j = 1;j<=n; j++){
        if(i - j < 0) continue;
        // yaha pe j liya hai
        int yahawala = j * (j + 1) / 2;
        int lastidx = i - j;
        int lastk = chahi - yahawala;
        if(lastk < 0) continue;
        if(dp[lastidx][lastk] == 1) {
            ans.push_back(j);
            f(dp, n, lastk, ans, lastidx);
            return ;
        }
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    int total = n * (n+1)/2;
    vector<vector<int> > dp(n+1, vector<int> (total+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i<=n; i++){
        for(int l = 0; l<=total ;l++){
            for(int j = 1; j<=n; j++){
                if(i - j < 0) continue;
                // yaha pe j liya hai
                int yahawala = j * (j + 1) / 2;
                int lastidx = i - j;
                int lastk = l - yahawala;
                if(lastk < 0) continue;
                if(dp[lastidx][lastk] == 1) {
                    dp[i][l] = 1;
                }
            }
        }
    }
    print2d(dp);
    int chahi = total - k;

    if(dp[n][chahi] == 1){
        vector<int> ans;
        f(dp, n, chahi, ans, n);
        reverse(ans.begin(), ans.end());
        // for(auto x: ans) cout<<x<<" ";
        // cout<<endl;
        set<int> st;
        for(int i = 1; i<=n; i++) st.insert(i);
        for(auto x : ans){
            set<int> curr;
            int cnt = 0;
            while(cnt < x){
                curr.insert(*st.rbegin());
                st.erase(--st.end());
                cnt++;
            }
            for(auto y: curr) cout<<y<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<0<<endl;
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
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

