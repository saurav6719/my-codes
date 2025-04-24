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

    int row;
    int col;
    if(n & 1){
        row = n+1;
    }
    else row = n;

    if(m & 1){
        col = m+1;
    }
    else col = m;

    vector<vector<int> > ans(row, vector<int> (col, -1));

    ans[0][0] = 0;
    ans[0][1] = 1;
    ans[1][0] = 2;
    ans[1][1] = 3;

    for(int i = 2; i<col; i++){
        if(ans[0][i-1] & 1){
            ans[0][i] = ans[0][i-1] + 3;
        }
        else ans[0][i] = ans[0][i-1]+1;
    }

    for(int i = 2; i<col; i++){
        if(ans[1][i-1] & 1){
            ans[1][i] = ans[1][i-1] + 3;
        }
        else ans[1][i] = ans[1][i-1]+1;
    }

    for(int i = 2; i<row; i++){
        for(int j = 0; j<col; j++){
            ans[i][j] = ans[i-2][j] + (1<<30);
        }
    }

    cout<<n*m<<endl;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<ans[i][j]<<" ";
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
    cin>>t;
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

