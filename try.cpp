/**
 *    author: Saurav
 *    created: 2024.11.11 18:30:41
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

bool f(int i, int t, vector<int> &input, vector<int> &p, int l, int k, vector<vector<int> > &dp){
    if(i == input.size()) return true;
    int currdepth = input[i] + p[t % (2*k)];
    if(i == 0) currdepth = 0;

    debug(i);
    debug(t);
    debug(currdepth);

    if(currdepth > l){
        return false;
    }
    if(t > 1e4) return false;
    if(dp[i][t] != -1) {
        if(dp[i][t] == 1) return true;
        return false;
    }
    // stay at current 
    if(f(i, t+1, input, p, l, k, dp)){
        dp[i][t] = 1;
        return true;
    }
    // go to next
    if(f(i+1, t+1, input, p, l, k, dp)){
        dp[i][t] = 1;
        return true;
    }
    dp[i][t] = 0;
    return false;
}
void solve(){
    int n,k,l;
    cin>>n>>k>>l;

    vector<int> input(n+1, 0);
    for(int i=1;i<=n;i++){
        cin>>input[i];
    }

    vector<vector<int> > dp(n+5, vector<int> (10005, -1));
    vector<int> p;
    for(int i = 0; i<=k; i++){
        p.push_back(i);
    }
    for(int i = k-1; i>=0; i--){
        p.push_back(i);
    }

    if(f(0,0,input, p,l,k,dp)){
        cout<<"Yes"<<endl;

    }else{
        cout<<"No"<<endl;
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

