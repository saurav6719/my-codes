/**
 *    author: Saurav
 *    created: 2025.05.01 05:23:43
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
#define printset(s)
#define printpp(v)
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
int query(int l, int r){
    cout<<"? "<<l<<" "<<r<<endl<<flush;
    int x;
    cin>>x;
    return x;
}
void solve(){
    int n;
    cin>>n;
    vector<int> dp;
    for(int i = 1; i<=n; i++){
        dp.push_back(i);
    }

    for(int i = 1; i<n; i++){
        print(dp);
        map<int,int> mp;
        for(int j = 0; j<dp.size() - 1; j++){
            int curr = dp[j];
            int next = dp[j + 1];
            if(next - curr == i){
                if(i==1){
                    int x = query(curr, next);
                    if(x > 0){
                        // curr is bigger than next 
                        mp[curr]++;
                    }
                    else mp[next]++;
                }
                else{
                    // need to do two searches
                    int x1 = query(curr,  next - 1);
                    int x2 = query(curr, next);
                    if(x1 == x2){
                        // next is bigger 
                        mp[next]++;
                    }
                    else mp[curr]++;
                }
            }
        }

        vector<int> newdp;
        for(auto ele : dp){
            if(mp[ele] > 0) newdp.push_back(ele);
        }

        dp = newdp;
        
    }

    cout<<"! "<<dp[0]<<endl<<flush;
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

