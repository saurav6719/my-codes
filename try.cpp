/**
 *    author: Saurav
 *    created: 2024.11.25 22:48:33
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
vector<int> dp;
int f(int i, vector<int> &interval, vector<int> &next, int n){
    if(i > n){
        return 0;
    }  

    if(dp[i] != -1){
        return dp[i];
    }

    int ans  =  0; 

    // take 
    ans = max(ans , interval[i] + f(next[i],interval,next,n));

    // leave
    ans = max(ans , f(i+1,interval,next,n));

    return dp[i] = ans;
}
void solve(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    dp.assign(n+1,-1);

    vector<pp> input(m);
    for(int i=0;i<m;i++){
        cin>>input[i].first>>input[i].second;
    }

    sort(input.begin(),input.end());
    int j = 0;

    vector<int> v(n+1);
    vector<int> intervals(n+1);
    int oc = 0;
    set<int> st;
    map<int,int> mp;
    for(int i = 1; i<=n; i++){
        while(j < m and input[j].first == i){
            st.insert(input[j].second);
            debug(input[j].second);
            oc++;
            mp[input[j].second]++;
            if(input[j].second == 4){
                debug(mp[input[j].second]);
            }
            j++;
        }
        if(st.size() == 0){
            v[i] = i+1;
        }
        else{
            v[i] = *st.rbegin() + 1;
        }

        intervals[i] = oc;

        if(st.count(i)){
            if(i==4){
                debug(i);
                debug(oc);
                debug(mp[i]);
            }
            st.erase(i);
            oc -= mp[i];
        }

    }

    print(v);
    print(intervals);

    cout<<f(1,intervals,v,n)<<endl;

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

