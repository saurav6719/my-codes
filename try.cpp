/**
 *    author: Saurav
 *    created: 2025.05.01 05:23:43
 *    We stop at Candidate Master in 2025
 **/

/* includes and all */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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


using namespace __gnu_pbds;

// Ordered Set
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
Operations:
- s.insert(x)       : Insert element x
- s.erase(x)        : Remove element x
- *s.find_by_order(k) : Get k-th smallest element (0-based index)
- s.order_of_key(x) : Get count of elements strictly smaller than x
*/

/* write core logic here */
int getsum(int l , int r , vector<int> &prfsum){
    if(l>r) return 0;
    return prfsum[r] - prfsum[l-1];
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> mp(n+1);

    ordered_set<int> s;
    for(int i = n-1; i>=0; i--){
        int ele = v[i];
        // right me chote 
        int cnt = s.order_of_key(ele);
        mp[ele] = cnt;

        s.insert(ele);
    }

    print(mp);

    vector<int> prfsum(n+1);
    prfsum[0] = mp[0];
    for(int i = 1; i<=n; i++){
        prfsum[i] = prfsum[i-1] + mp[i];
    }
    int orans = getsum(1, n, prfsum);

    vector<int> kitnemeaaraha(n+1, 0);

    {
        ordered_set<int> st1;
        for(int i = 0; i<n; i++){
            int ele = v[i];
            // left me bade
            int cnt = st1.order_of_key(ele);
            int bade = st1.size() - cnt;
            kitnemeaaraha[ele] = bade;
            st1.insert(ele);
        }
        print(kitnemeaaraha);
    }

    vector<int> prfsum2(n+1);
    prfsum2[0] = kitnemeaaraha[0];
    for(int i = 1; i<=n; i++){
        prfsum2[i] = prfsum2[i-1] + kitnemeaaraha[i];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        if(l == r){
            cout<<0<<endl;
            continue;
        }
        int one = getsum(l+1, r, prfsum);
        debug(one);
        one += getsum(r+1, n, prfsum);
        debug(one);
        one -=  getsum(r, n, prfsum2);
        cout<<one<<endl;
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
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

