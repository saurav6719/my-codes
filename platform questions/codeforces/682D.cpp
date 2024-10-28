/**
 *    author: Saurav
 *    created: 2024.10.28 14:55:36
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
int dp[1001][1001][11][2];
int f(int i, int j, int k,bool consec,  string & str1, string &str2){
    if(i == str1.size()){
        if(k==0) return 0;
        return -1e9;
    }
    if(j == str2.size()){
        if(k==0) return 0;
        return -1e9;
    }

    if(k==0) return 0;

    if(dp[i][j][k][consec] != -1) return dp[i][j][k][consec];

    int ans = 0;
    if(consec == false) ans = max(ans , f(i+1, j, k, false, str1, str2));
    if(consec == false) ans = max(ans , f(i, j+1, k,false, str1, str2));

    if(str1[i] == str2[j]){
        ans = max(ans , 1 + f(i+1, j+1, k-1,false,  str1, str2));
        ans = max(ans , 1 + f(i+1, j+1, k,true,  str1, str2));
    }

    return dp[i][j][k][consec] = ans;


}
void solve(){
    int n;
    int m;
    int k;
    cin>>n>>m>>k;

    string str1;
    string str2;
    cin>>str1>>str2;

    memset(dp, -1, sizeof(dp));

    cout<<f(0, 0, k,false, str1, str2)<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t/;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

