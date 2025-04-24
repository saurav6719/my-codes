/**
 *    author: Saurav
 *    created: 2024.10.17 01:49:12
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
    int n;
    cin>>n;
    vector<pp> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first;
        cin>>input[i].second;
    }
    sort(input.begin(), input.end());

    multiset<int> stb;
    for(auto ele : input){
        stb.insert(ele.second);
    }

    multiset<int> stbdone;

    int ans = 1e15;
    for(int i = 0; i<n; i++){
        // considering this first as maximum for one girlfriend
        // then after this we have to select all from second element coz first will be greater 
        // erase the current second from set as first is selected so cant select second 
        stb.erase(stb.find(input[i].second));
        int mx = stb.size() ? *stb.rbegin() : -1e15;

        ans = min(ans , abs(input[i].first - mx));


        // now lets say current remainining second is so small thatabsolute difference is quite high 
        // we can select any of the previous second because by doing this amax is still a[i] as a is sorted 
        // so we select that second from i-1 to 0 that minimise absolute difference 
        // so select closest number to a[i] from stbdone

        auto it = stbdone.lower_bound(input[i].first);
        if(it != stbdone.end()){
            int nmx = max(mx , *it);
            ans = min(ans , abs(input[i].first - nmx));
        }
        if(it != stbdone.begin()){
            --it;
            int nmx = max(mx , *it);
            ans = min(ans , abs(input[i].first - nmx));
        }

        stbdone.insert(input[i].second);
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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

