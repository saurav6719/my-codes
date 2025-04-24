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

int f(vector<int> &score, int n, int mask, vector<int> &dp2){
    if(mask == 0) return 0;
    if(dp2[mask] > INT_MIN) return dp2[mask];
    int ans = 0;
    for(int submask = mask ; submask!=0; submask= ((submask-1) & mask)){
        ans = max(ans, score[submask] + f(score,n, (mask ^ submask), dp2));

    }
    return dp2[mask] = ans;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int> > input(n , vector<int> (n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>input[i][j];
        }
    }

    vector<int> score((1<<n) + 5 , -1);
    score[0] = 0;
    for(int mask = 0; mask < (1 << n); mask++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                for(int j = i+1; j < n; j++){
                    if(mask & (1 << j)){
                        sum += input[i][j];
                    }
                }
            }
        }
        score[mask] = sum;
    }
    vector<int> dp2((1<<n)+5 , INT_MIN);
    cout<<f(score, n,(1<<n) - 1, dp2);
    //print(dp);
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

