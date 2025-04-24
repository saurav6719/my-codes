/**
 *    author: Saurav
 *    created: 2024.10.15 17:46:34
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
int dp[501][501][11];
int f(int i, int j, int k, vector<vector<int> > &input1, vector<vector<int> > &input2, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m) return 1e15;
    if(k==0) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];

    // go left
    int left = 1e15;
    if(j>0){
        left = f(i, j-1, k-1, input1, input2, n ,m) + input1[i][j-1];
    }
    int right = 1e15;
    if(j<m-1){
        right = f(i, j+1, k-1, input1, input2, n ,m) + input1[i][j];
    }

    int up = 1e15;
    if(i>0){
        up = f(i-1, j, k-1, input1, input2, n ,m) + input2[i-1][j];
    }
    int down = 1e15;
    if(i<n-1){
        down = f(i+1, j, k-1, input1, input2, n ,m) + input2[i][j];
    }

    return dp[i][j][k] = min({left, right, up, down});
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int> > input1(n, vector<int> (m-1));
    vector<vector<int> > input2(n-1, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            cin>>input1[i][j];
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            cin>>input2[i][j];
        }
    }

    memset(dp, -1, sizeof dp);

    vector<vector<int> > ans(n, vector<int> (m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m;j++){
            if(k & 1){
                ans[i][j] = -1;
                continue;
            }
            ans[i][j] = f(i, j, k/2, input1, input2, n, m);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans[i][j] == -1) cout<<-1<<" ";
            else cout<<2*ans[i][j]<<" ";
        }
        cout<<endl;
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

