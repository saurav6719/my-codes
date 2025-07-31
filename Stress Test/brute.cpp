/**
 *    author: Saurav
 *    created: 2025.07.11 17:03:07
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
void solve(){
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int n = s1.size();
    vector<pp> v(n, {-1, n+1});

    for(int i = 0; i<n; i++){
        if(s1[i] == 'N'){
            v[i] = {i, i};
        }
        else {
            int l = -1;
            int r = n+1;
            if(i-1 < 0) continue;
            if(i + 1>= n) continue;

            if(s2[i-1] == 'N') l = i-1;
            if(s2[i+1] == 'N') r = i+1;
            if(l == -1){
                if(i-2>=0 and s1[i-2] == 'D') l = i-2;
            }
            if(r == n+1){
                if(i+2 < n and s1[i+2] == 'D') r = i+2;
            }
            v[i] = {l, r};
        }
    }
    int q = 1;

    vector<int> prf(n, 0);
    for(int i = 0; i<n; i++){
        if(v[i].first == -1 || v[i].second == n+1) continue;
        prf[i] = 1;
    }
    vector<int> prf2 = prf;

    for(int i = 1; i<n; i++){
        prf[i] += prf[i-1];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        l--; r--;
        int ans = 0;

        if(r-l+1 <= 10){
            for(int i = l; i<=r; i++){
                if(v[i].first >= l and v[i].second <= r) ans++;
            }
            cout<<ans<<endl;
        }
        else{
            int ans = 0;
            for(int i = l; i<l+5; i++){
                if(v[i].first >= l and v[i].second <= r) ans++;
            }
            for(int i = r-4; i<=r; i++){
                if(v[i].first >= l and v[i].second <= r) ans++;
            }
            int l1 = l+5;
            int r1 = r-5;
            ans += prf[r1] - (l1 == 0 ? 0 : prf[l1-1]);
            cout<<ans<<endl;
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

