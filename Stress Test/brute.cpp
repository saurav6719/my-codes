/**
 *    author: Saurav
 *    created: 2025.09.20 17:35:00
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
void divisors(int n, vector<int> &v){
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            v.push_back(i);
            if(i != n/i) v.push_back(n/i);
        }
    }
}
void solve(){
    int n,x;
    cin>>n>>x;
    int d1 = n - x;
    int d2 = n + x - 2;
    vector<int> v1, v2;
    divisors(d1, v1);
    divisors(d2, v2);

    set<int> ans;
    for(auto it : v1){
        // 2k-2 = x
        int k = (it + 2) / 2;
        if((it + 2) % 2 != 0) continue;
        // is k pe n pe kya answer hoga
        int rem = n % ((2*k)- 2);

        if(rem == 0 and x == 2){
            ans.insert(k);
        }
        else if(rem <= k and x == rem){
            ans.insert(k);
        }
        else if(rem > k){
            int honachahiye = k - (rem - k);
            if(honachahiye == x) ans.insert(k);
        }
    }
    for(auto it : v2){
        // 2k - 2 = x
        int k = (it + 2)/2;
        if((it + 2) % 2 != 0) continue;
        // is k pe n pe kya answer hoga
        int rem = n % ((2*k) - 2);
        if(rem == 0 and x == 2){
            ans.insert(k);
        }
        else if(rem <= k and x == rem){
            ans.insert(k);
        }
        else if(rem > k){
            int honachahiye = k - (rem - k);
            if(honachahiye == x) ans.insert(k);
        }
    }

    cout<<ans.size()<<endl;
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

