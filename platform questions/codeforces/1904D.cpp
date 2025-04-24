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
#define inf  1e18+5
using namespace std;

/* write core logic here */
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> input(n);
    int mindf = inf;
    int mini =inf;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        mini = min(mini, input[i]);
    }
    sort(input.begin(), input.end());
    if(k>=3){
        cout<<0<<endl;
        return;
    }
    if(k==1){
        int ans = inf;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i==j) continue;
                ans = min(ans, abs(input[i] - input[j]));
            }
        }
        ans = min(ans, mini);
        cout<<ans<<endl;
        return;
    }


    int ans =inf;
    int diff20 = inf;

    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i==j) continue;
            int aa = (abs(input[i] - input[j]));
            diff20 = min(diff20, aa);
            int it = lower_bound(input.begin(), input.end(), aa)- input.begin();
            int xx;
            if(it<n) xx = abs(input[it]-aa);
            else xx = inf;
            int yy;
            if(it>0) yy = abs(input[it-1] - aa);
            else yy = inf;
            ans = min(ans, xx);
            ans = min(ans,yy);
        }
    }
    ans = min(ans, diff20);
    cout<<ans<<endl;
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

