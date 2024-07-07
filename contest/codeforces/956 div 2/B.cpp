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
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int> > g1(n, vector<int> (m));

    for(int i = 0; i<n; i++){
      for(int j = 0; j<m; j++){
        char c;
        cin>>c;
        g1[i][j] = c-'0';
      }
    }

    vector<vector<int> > g2(n, vector<int> (m));

    for(int i = 0; i<n; i++){
      for(int j = 0; j<m; j++){
        char c;
        cin>>c;
        g2[i][j] = c-'0';
      }
    }


    for(int i = 0; i<n-1; i++){
      for(int j = 0; j<m-1; j++){
        if(g1[i][j] == g2[i][j]) continue;
        if(g1[i][j] < g2[i][j]){
          int diff = g2[i][j] - g1[i][j];
          g1[i][j] = g2[i][j];
          g1[i+1][j+1] += diff;
          g1[i+1][j+1] %= 3;
          if(diff == 1){
            g1[i+1][j] += 2;
            g1[i+1][j] %= 3;
            g1[i][j+1] += 2;
            g1[i][j+1] %= 3;
          }
          else{
            g1[i+1][j] += 1;
            g1[i+1][j] %= 3;
            g1[i][j+1] += 1;
            g1[i][j+1] %= 3;
          }
        }
        
        
        if(g1[i][j] > g2[i][j]){
          int diff = g2[i][j] + 3 - g1[i][j];
          g1[i][j] = g2[i][j];
          g1[i+1][j+1] += diff;
          g1[i+1][j+1] %= 3;
          if(diff == 1){
            g1[i+1][j] += 2;
            g1[i+1][j] %= 3;
            g1[i][j+1] += 2;
            g1[i][j+1] %= 3;
          }
          else{
            g1[i+1][j] += 1;
            g1[i+1][j] %= 3;
            g1[i][j+1] += 1;
            g1[i][j+1] %= 3;
          }
        }

      }
    }


    for(int i = 0; i<n; i++){
      for(int j = 0; j<m; j++){
        if(g1[i][j] != g2[i][j]){
          cout<<"NO"<<endl;
          return;
        }
      }
    }

    cout<<"YES"<<endl;
    

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

