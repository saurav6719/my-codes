/**
 *    author: Saurav
 *    created: 2025.12.05 19:23:37
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
    string s;
    vector<pp> intervals;
    int cnt = 192;
    while(cnt--){
        cin>>s;
        if(s.empty()){
            break;
        }
        print(s);
        string one = "";
        string two = "";
        int i = 0;
        while(i < s.size() && s[i] != '-'){
            one += s[i];
            i++;
        }
        i++; // skip '-'
        while(i < s.size()){
            two += s[i];
            i++;
        }
        intervals.push_back({stoll(one), stoll(two)});
    }
    vector<int> queries;
    cin.ignore();
    int x;
    while(cin>>x){
        queries.push_back(x);
    }

    sort(intervals.begin(), intervals.end());
    int l = intervals[0].first;
    int r = intervals[0].second;

    vector<pp> merged;

    for(int i = 1; i<intervals.size(); i++){
        if(intervals[i].first <= r){
            r = max(r, intervals[i].second);
        } else {
            merged.push_back({l,r});
            l = intervals[i].first;
            r = intervals[i].second;
        }
    }
    merged.push_back({l,r});

    int ans = 0;
    for(auto q : queries){
        auto ub = upper_bound(merged.begin(), merged.end(), make_pair(q, LLONG_MAX));
        if(ub == merged.begin()){
            continue;
        }
        ub--;
        if(ub->first <= q && q <= ub->second){
            ans++;
        }
    }

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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

