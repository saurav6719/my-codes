/**
 *    author: Saurav
 *    created: 2025.06.23 21:44:49
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
vector<int> prime_factors(long long n) {
    vector<int> fac;

    // 2 के लिये अलग से—fast even-stripping
    while (n % 2 == 0) {
        fac.push_back(2);
        n /= 2;
    }

    // odd candidates 3,5,7,…√n तक
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            fac.push_back((int)i);
            n /= i;
        }
    }

    // बचे-खुचे n में अगर कोई बड़ा prime रह गया
    if (n > 1) fac.push_back((int)n);

    return fac;
}
vector<int> v;
void precompute(){
    v.resize(500005);
    v[1] = 1;
    for(int i = 2; i<=500000; i++){
        if(i % 2 == 0){
            v[i] = 0;
            continue;
        }
        else{
            vector<int> factors = prime_factors(i);
            if(factors.size() == 1){
                v[i] = v[i-2] + 1;
                continue;
            }
            int ans = 0;
            for(auto ele : factors){
                ans += v[ele] - 1;
            }
            v[i] = ans + 1;
        }
    }
}
void solve(){
    int m;
    cin>>m;
    if(m % 2 == 0){
        cout<<-1<<endl;
        return;
    }
    cout<<v[m]<<endl;
    return;
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
    precompute();
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

