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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char > > grid(n, vector<char> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int> > dp(n, vector<int> (m));
    for(int j = 0; j<m;j++){
        if(grid[0][j] == '.') dp[0][j] = 1;
        else dp[0][j] = 0;
    }

    for(int i = 0; i<n;i++){
        if(grid[i][0] == '.') dp[i][0] = 1;
        else dp[i][0] = 0;
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(grid[i][j] == 'X'){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
            }
        }
    }

    set<int> columns;

    for(int i = 1; i<n;i++){
        for(int j = 1; j<m;j++){
            if(grid[i-1][j] == 'X' and grid[i][j-1] == 'X'){
                columns.insert(j);
            }
        }
    }

    print2d(dp);

    vector<int> xx;
    for(auto ele : columns){
        xx.push_back(ele);
    }

    sort(xx.begin(), xx.end());


    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;


        int lb1 = lower_bound(xx.begin(), xx.end(), x) - xx.begin();
        int lb2 = lower_bound(xx.begin(), xx.end(), y) - xx.begin();

        debug(lb1);
        debug(lb2);

        int a;
        int b;

        if(lb1 < xx.size()){
            a = xx[lb1];
        }
        else a = m+1;

        if(lb2 < xx.size()){
            b = xx[lb2];
        }
        else b = m+1;

        debug(a);
        debug(b);

        if(a==x and b>y){
            if(lb1 + 1 == xx.size() or xx[lb1 + 1] > y){
                cout<<"YES"<<endl;
                continue;
            }
        }

        if(a==b and a==x and a==y){
            cout<<"YES"<<endl;
            continue;
        }

        if(a > y and b > y){
            cout<<"YES"<<endl;
            continue;
        }

        cout<<"NO"<<endl;

        
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

