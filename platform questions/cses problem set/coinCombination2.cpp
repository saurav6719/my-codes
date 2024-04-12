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
    cin>>n;
    int x; 
    cin>>x;
    vector<int> nums(n);

    vector<int> next(x+1,0);

    for(int i = 0; i<n; i++){
        cin>>nums[i];
    }
    //base case
    next[x] = 1;
    for(int i = n-1; i>=0;i--){
        vector<int> current(x+1,0);
        for(int j = x; j>=0;j--){
            int pick = 0;
            int skip = next[j];
            if(j+nums[i] <= x){
                //pick kr skte hai
                pick = current[j+nums[i]];
            }
            current[j] = (skip % mod + pick %mod)%mod;
        }
        next = current;
    }
    cout<<next[0];
    
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