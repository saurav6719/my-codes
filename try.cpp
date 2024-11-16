/**
 *    author: Saurav
 *    created: 2024.11.16 20:28:36
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
void solve(){
    int n; cin>>n;
    string s[n];
    vector <vector<int>> f(n, vector<int>(26, 0));
    vector <int> mask(n, 0);
    
    for (int i=0; i<n; i++){
        cin>>s[i];
        
        for (auto x: s[i]){
            f[i][x-'a']++;
        }
        
        for (int j=0; j<26; j++){
            if (f[i][j] & 1) 
            mask[i] += 1<<j;
        }
    }
    
    int ans = 0;
    int tot = (1<<26) - 1;
    
    for (int miss = 0; miss <26; miss++){
        unordered_map <int, int> good;
        int req = tot - (1<<miss);
        for (int i=0; i<n; i++){
            if (f[i][miss]) continue;
            
            ans += good[req ^ mask[i]];
            good[mask[i]]++;
        }
    }
    
    cout<<ans<<"\n";

}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
}`