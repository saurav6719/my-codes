/**
 *    author: Saurav
 *    created: 2024.11.17 03:52:29
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
vector<vector<int>> dp;
int f(int i, int last, vector<int> &cold, vector<int> &hot, vector<int> &sequence){
    int n = sequence.size();
    if(i==n) return 0;

    if(dp[i][last] != -1) return dp[i][last];

    // option 1 run at cpu where prev index got run 

    int prev = sequence[i-1];
    int option1;
    int option2;
    if(sequence[i] == prev){
        option1 = f(i+1, last, cold, hot, sequence) + hot[sequence[i]];
    }
    else{
        option1 = f(i+1, last, cold, hot, sequence) + cold[sequence[i]];
    }

    // option 2 run at cpu where last index got run

    
    if(sequence[last] == sequence[i]){
        option2 = f(i+1, i-1, cold, hot, sequence) + hot[sequence[i]];
    }
    else{
        option2 = f(i+1, i-1, cold, hot, sequence) + cold[sequence[i]];
    }

    return dp[i][last] = min(option1, option2);

}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1, 0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<int> a(k+1 , 0);
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    vector<int> b(k+1, 0);
    for(int i=1;i<=k;i++){
        cin>>b[i];
    }

    dp.clear();
    dp.resize(n+1, vector<int>(n+1, -1));

    int ans = f(1, 0, a, b, v);

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

