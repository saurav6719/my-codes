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
    vector<int> nums = {1,9,9,7,4};
    int n = nums.size();
    int k = 1;
    vector<int> mark(n+5, 0);

    for(int i = 0; i<n; i++){
        if(((nums[i] & k) == k)) {
            mark[i] = 1;
            // debug(nums[i]);
        }
        else {
            //debug(nums[i]);
            mark[i] = 0; 
        }
    }   

    vector<int> last;

    last.push_back(-1);

    print(mark);

    vector<int> check(n+5, -5);

    for(int i = 1; i<n; i++){
        if((nums[i] & nums[i-1]) == k){
            check[i] = 1;
        }
        else{
            check[i] = -1;
        }
    }

    print(check);


    for(int i = 0; i<n; i++){
        if(check[i] == -1) last.push_back(i);
    }
    last.push_back(n);
    int ans = 0 ;
    for(int i = 0; i<n; i++){
        if(nums[i] == k) ans++;
    }

    debug(ans);

    print(last);



    for(int i = 1; i<n; i++){
        if(check[i] == -1) continue;
        int xx = lower_bound(last.begin(), last.end(), i)- last.begin();
        debug(xx);
  
        if(xx==1){
            int nmber = i+1;
            ans += nmber-1;
            debug(ans);
        }
        
        else{
            xx--;
            int nmber = i - last[xx];
            ans += nmber-1;
        }

        
    }

    cout<<ans;


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

