/**
 *    author: Saurav
 *    created: 2025.06.29 02:33:29
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
vector<int> primefactorisation(int n){
    vector<int> factors;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            factors.push_back(i);
            n/=i;
        }
    }
    if(n>1) factors.push_back(n);
    return factors;
}

int f(int l, int r, vector<vector<int> > &dp){
    if(l > r) return 0;
    if(l == r) return 1;
    if(dp[l][0] >= r) return 1;


    for(int j = 30; j>=0; j--){
        if(dp[l][j] <= r){
            return (1<<j) + f(dp[l][j] + 1, r, dp);
        }
    }

    return -1;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<vector<int> > dp(n, vector<int> (31));
    int i = 0;
    int j = 0;
    multiset<int> st;
    while(i<n){
        if(j >= n){
            dp[i][0] = n;
            i++;
            continue;
        }
        int x = a[j];
        vector<int> factors = primefactorisation(x);
        bool ok = true;
        for(int f:factors){
            if(st.count(f) > 0){
                ok = false;
                break;
            }
        }
        if(ok){
            for(int f:factors){
                st.insert(f);
            }
            j++;
        }
        else{
            dp[i][0] = j-1;
            int y = a[i];
            vector<int> y_factors = primefactorisation(y);
            for(int f:y_factors){
                st.erase(st.find(f));
            }
            i++;
        }
    }

    for(int j = 1; j<=30; j++){
        for(int i = 0; i<n; i++){
            if(dp[i][j-1] >= n-1){
                dp[i][j] = n;
                continue;
            }
            dp[i][j] = dp[dp[i][j-1] + 1][j-1];
            
        }
    }
    print2d(dp);

    // for(int i = 0; i<n; i++){
    //     cout<<dp[i][0]<<" ";
    // }

    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if(l == r){
            cout<<1<<endl;
            continue;
        }
        int ans = f(l, r, dp);
        cout<<ans<<endl;
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

