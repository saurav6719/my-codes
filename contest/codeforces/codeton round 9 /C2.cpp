/**
 *    author: Saurav
 *    created: 2024.11.23 22:20:19
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
vector<int> findFactors(int x) {
    vector<int> factors;

    // Iterate from 1 to sqrt(x) to find factors
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            factors.push_back(i);       // Add the smaller factor
            if (i != 1 && x / i != x)  // Add the larger factor (if not x itself)
                factors.push_back(x / i);
        }
    }
    return factors;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> input(m);
    for(auto &x : input){
        cin>>x;
    }
    sort(input.begin(),input.end(), greater<int>()) ;

    print(input);

    vector<int> ans(n+1);
    ans[1] = input[0];
    for(int i = 2 ; i<=n; i++){
        vector<int> factors = findFactors(i);

        if(i==4){
            print(factors);
        }
        set<int> st;
        for(auto x : factors){
            st.insert(ans[x]);
        }
        int sz = st.size();
        if(sz == m){
            cout<<-1<<endl;
            return ;
        }
        ans[i] = input[sz];
    }

    for(int i = 1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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

