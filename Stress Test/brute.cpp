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
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0 ; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i<n; i++){
        cin>>b[i];
    }
    map<int,int> mp1even;
    map<int,int> mp1odd;
    map<int,int> mp2even;   
    map<int,int> mp2odd;

    for(int i = n-1; i>=0; i--){
        // kya is i tak possible hai
        if(a[i] == b[i]){
            cout<<i+1<<endl;
            return;
        }
        if(i % 2 == 0){
            {
                // dusre ke even me agar hai to yes 
                // same ke odd me agar hai to yes
                if(mp1even.find(b[i]) != mp1even.end() or mp2even.find(a[i]) != mp2even.end()){
                    cout<<i+1<<endl;
                    return;
                }
                if(mp1odd.find(a[i] ) != mp1odd.end() or mp2odd.find(b[i]) != mp2odd.end()){
                    cout<<i+1<<endl;
                    return;
                }
            }
            {
                // ek remove krte hai aage se 
                if(mp1even.find(a[i]) != mp1even.end()){
                    int index = mp1even[a[i]];
                    if(index > i+1){
                        cout<<i+1<<endl;
                        return;
                    }
                }
                if(mp2even.find(b[i]) != mp2even.end()){
                    int index = mp2even[b[i]];
                    if(index > i+1){
                        cout<<i+1<<endl;
                        return;
                    }
                }
                if(mp1odd.find(b[i]) != mp1odd.end()){
                    int index = mp1odd[b[i]];
                    if(index > i+1){
                        cout<<i+1<<endl;
                        return;
                    }
                }
                if(mp2odd.find(a[i]) != mp2odd.end()){
                    int index = mp2odd[a[i]];  
                    if(index > i+1){
                        cout<<i+1<<endl;
                        return;
                    }
                }
            }

            mp1even[a[i]] = max(mp1even[a[i]], i);
            mp2even[b[i]] = max(mp2even[b[i]], i);
        }
        else{
            // dusre ke odd me agar hai to yes 
            // same ke even me agar hai to yes
            if(mp1odd.find(b[i]) != mp1odd.end() or mp2odd.find(a[i]) != mp2odd.end()){
                cout<<i+1<<endl;
                return;
            }
            if(mp1even.find(a[i] ) != mp1even.end() or mp2even.find(b[i]) != mp2even.end()){
                cout<<i+1<<endl;
                return;
            }
            {
                // ek remove krte hai aage se 
                if(mp1odd.find(a[i]) != mp1odd.end()){
                    int index = mp1odd[a[i]];
                    if(index > i+1){
                        cout<<i+1<<endl;
                        return;
                    }
                }
                if(mp2odd.find(b[i]) != mp2odd.end()){
                    int index = mp2odd[b[i]];
                    if(index > i+1){
                        cout<<i+1<<endl;
                        return;
                    }
                }
                if(mp1even.find(b[i]) != mp1even.end()){
                    int index = mp1even[b[i]];
                    if(index > i+1){
                        cout<<i+1<<endl;
                        return;
                    }
                }
                if(mp2even.find(a[i]) != mp2even.end()){
                    int index = mp2even[a[i]];  
                    if(index > i+1){
                        cout<<i+1<<endl;
                        return;
                    }
                }
            }

            mp1odd[a[i]] = max(mp1odd[a[i]], i);
            mp2odd[b[i]] = max(mp2odd[b[i]], i);

        }
    }

    cout<<0<<endl;
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