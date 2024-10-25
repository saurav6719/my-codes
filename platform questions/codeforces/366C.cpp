/**
 *    author: Saurav
 *    created: 2024.10.25 19:20:55
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

int dp[101][30001];
int f(int i, int balance, vector<int> &taste, vector<int> &calory, int k){
    if(i== taste.size()){
        if(balance == 20000){
            return 0;
        }
        return -1e12;
    }

    if(balance < 0){
        return -1e12;
    }

    debug(i);
    debug(balance);
    debug(taste[i]);
    debug(calory[i]);

    if(dp[i][balance] != -1){
        return dp[i][balance];
    }

    int pick = -1;
    int notpick = -1;
    pick = taste[i] + f(i+1, balance + taste[i] - (k*calory[i]) , taste, calory, k);

    notpick = f(i+1, balance, taste, calory, k);
    return dp[i][balance] = max(pick, notpick);
}
void solve(){
    int n;
    cin>>n;

    int k;
    cin>>k;
    vector<int> taste(n);
    for(int i=0;i<n;i++){
        cin>>taste[i];
    }

    memset(dp, -1, sizeof dp);
    vector<int> calories(n);
    for(int i=0;i<n;i++){
        cin>>calories[i];
    }
    int xx = f(0, 20000, taste, calories, k);
    if(xx < -1 or xx == 0) xx  = -1;
    cout<<xx<<endl;
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

