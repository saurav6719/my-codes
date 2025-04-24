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
double dp[1<<20];

double pmove(int prev_bitmask, int j, int n , vector<vector<double> > &prob ){ // we want j to die
    int k = __builtin_popcount(prev_bitmask);
    int den = (k * (k-1)) / 2;

    double ans = 0;
    for(int fish  = 0 ; fish <n; fish++){
        if((1<<fish) & (prev_bitmask)){ // if prev_bitmask me fish jinda ho
            ans += prob[fish][j]; // j die 
        }
    }

    return ans / (1.0 * den);
}

double f(int bitmask , int n, vector<vector<double> > &prob ){
    int alive = __builtin_popcount(bitmask);
    if(alive == n) return 1;
    if(dp[bitmask] > -0.9) return dp[bitmask];
    double ans = 0;
    for(int fish = 0; fish < n; fish++){
        if(!((1<<fish) & bitmask)){
            // fish is dead now 
            // fish can be alive before 
            int prev_bitmask = bitmask ^ (1<<fish);
            double prev_prob = f(prev_bitmask , n , prob);
            ans += prev_prob *  pmove(prev_bitmask , fish , n, prob);
        }
    }

    return dp[bitmask] = ans;

}

void solve(){
    int n;
    cin>>n;
    vector<vector<double> > prob(n, vector<double> (n));
    memset(dp , -1, sizeof dp);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>prob[i][j];
        }
    }


    for(int i = 0; i<n; i++){
        cout<<fixed<<setprecision(6)<<f((1<<i) , n, prob)<<" ";
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

