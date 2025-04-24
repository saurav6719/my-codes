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
bool comp(pair<pair<int,int> , int> &a, pair<pair<int,int> ,int> &b){
    return a.first.second < b.first.second;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<pair<int,int>, int > > input(n);
    for(int i = 0 ; i<n; i++){
        cin>>input[i].first.first>>input[i].first.second;
        cin>>input[i].second;
    }
    sort(input.begin(), input.end(), comp);
    vector<int> ends;
    ends.push_back(0);
    for(int i = 0 ;i<n; i++){
        ends.push_back(input[i].first.second);
    }
    print(ends);
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i = 1; i<=n; i++){
        int ele = input[i-1].first.first;
        debug(ele);
        int lw = lower_bound(ends.begin(), ends.end(), ele)- ends.begin();
        debug(lw);
        dp[i] = max(dp[i-1], dp[lw-1] + input[i-1].second);
        debug(dp[i]);
    }

    cout<<dp[n]<<endl;



    
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

