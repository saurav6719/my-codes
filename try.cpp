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
    int n;cin>>n;
    set<int> present;
    set<int> absent;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
        present.insert(input[i]);
    }

    for(int i = 1; i<=2*n; i++){
        if(present.count(i) == 0){
            absent.insert(i);
        }
    }

    vector<int> a(n, 0);
    vector<int> b(n, 0);

    {
        set<int> abscopy = absent;
        for(int i = n-1 ; i>=0; i--){
            auto it = abscopy.upper_bound(input[i]);
            if(it == abscopy.begin()) break;
            it--;
            if(*it < input[i]){
                a[i] = 1;
                abscopy.erase(*it);
            }
            else break;
            debug(input[i]);
            debug(*it);
        }
    }
    {
        set<int> abscopy = absent;
        for(int i = 0; i<n; i++){
            auto it = abscopy.upper_bound(input[i]);
            if(it == abscopy.end()) break;
            abscopy.erase(*it);
            b[i] = 1;
        }
    }

    print(a);
    print(b);

    int ans = 0;
    set<int> thosex;

    for(int i = 1; i<n; i++){
        if(a[i] == 1 and b[i-1] == 1){
            thosex.insert(i-1);
        }
    }

    if(a[0] == 1) thosex.insert(-1);

    for(int i = 0; i<n-1; i++){
        if(b[i] == 1 and a[i+1] == 1){
            thosex.insert(i);
        }
    }

    if(b[n-1] == 1) thosex.insert(n-1);
    ans = thosex.size();
    cout<<ans<<endl;
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

