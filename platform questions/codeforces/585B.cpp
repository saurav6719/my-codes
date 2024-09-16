/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

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
int dp[4][105][105];
bool f(int i,int j, int time, int n, vector<vector<set<int> > > &timing){
    if(j >= n) {
        // debug(time);
        return true;
    }
    // debug(i);
    // debug(j);

    if(timing[i][j].count(time-1) or timing[i][j].count(time)) return false;

    if(j+1 < n and timing[i][j+1].count(time)) return false;

    if(dp[i][j][time] != -1) return dp[i][j][time];

    if(i == 0) {
        int xx = f(1, j+1, time+1, n, timing);
        int yy = f(0, j+1, time+1, n, timing);
        // debug(xx);
        // debug(yy);
        if(xx or yy){
            return dp[i][j][time] = true;
        }
    }

    if(i==1){
        int aa = f(1, j+1, time+1, n, timing);
        int bb = f(0, j+1, time+1, n, timing);
        int cc = f(2, j+1, time+1, n, timing);
        // debug(aa);
        // debug(bb);
        // debug(cc);
        return dp[i][j][time] = aa or bb or cc;
    }

    if(i==2){
        int dd = f(1, j+1, time+1, n, timing);
        int ee = f(2, j+1, time+1, n, timing);

        // debug(dd);
        // debug(ee);
        return dp[i][j][time] = dd or ee;
    }
    return dp[i][j][time] = false;

}   
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<char> > input(3, vector<char> (n));
    int starti = -1;
    int startj = -1;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<n; j++){
            cin>>input[i][j];

            if(input[i][j] == 's'){
                starti = i;
                startj = j;
            }
        }
    }

    

    vector<vector<set<int> > > timing(3, vector<set<int> > (n, set<int> ()));

    for(int i = 0; i<3; i++){
        for(int j = 0; j<n; j++){
            if(input[i][j] != '.' and input[i][j] != 's'){
                timing[i][j].insert(0);
            }
        }
    }

    for(int i = 0; i<3; i++){
        for(int j = 0; j<n; j++){
            for(int t = 0; t<=100; t++){
                int col = j;
                int currt = t;
                while(col < n and currt>=0 ){
                    if(timing[i][col].count(currt)){
                        timing[i][j].insert(t);
                    }
                    currt--;
                    col+=2;
                }
            }
        }
    }

    memset(dp, -1, sizeof dp);

    // for(int i =2; i<3; i++){
    //     for(int j = 0; j<n; j++){
    //         cout<<i<<", "<<j<<"- >";
    //         for(auto ele : timing[i][j]){
    //             cout<<ele<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    // debug(starti);
    // debug(startj);

    bool xx = f(starti, startj, 0, n, timing);
    debug(xx);

    debug(f(2,2,2,n,timing));

    if(xx) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    // cout<<"YES"<<endl;



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

