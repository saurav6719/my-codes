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

double dp[1001][1001][2];
const double UNVISITED = -1.0;
const long double EPSILON = 1e-9;


double f(int w, int b, bool princess){
    // Base Cases

    if(w < 0 || b < 0) return 0; // Or handle as per problem logic
    if(princess){
        if(w == 0) return 0;
        if(b == 0) return 1;
    }
    else{
        if(w == 0) return 1;
        if(b == 0) return 0;
    }

    // Memoization Check
    if(dp[w][b][princess] != UNVISITED) return dp[w][b][princess];

    double t = w + b;
    if(!princess){
        double xx = ((double)b / t) * f(w-1, b-1, true) * ((double)w / (t-1));
        double yy = ((double)b / t) * f(w, b-2, true) * ((double)(b-1) / (t-1));
        return dp[w][b][princess] = xx + yy;
    }
    else{
        double xx = ((double)w / t);
        double yy = ((double)b / t) * f(w, b-1, false);
        return dp[w][b][princess] = xx + yy;
    }
}
void solve(){
    int w, b;
    cin>>w>>b;
    for(int i = 0; i <= 1000; ++i){
        for(int j = 0; j <= 1000; ++j){
            dp[i][j][0] = UNVISITED;
            dp[i][j][1] = UNVISITED;
        }
    }

    // debug(f(5,2,true));

    cout<<fixed<<setprecision(9)<<f(w,b,true)<<endl;
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

