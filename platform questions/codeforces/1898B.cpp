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
pair<int,int>  f(int num, int mini){
    if(num <= mini){
        return {0,num};
    }
    int ff = 1 + f(num/2 , mini).first + f(num - num/2 , mini).first;
    int ss = mn(mini , f(num/2 , mini).second, f(num - num/2 , mini).second);

    return {ff,ss}; 
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int mini = input[n-1];

    int ans = 0;
    int idx = -1;

    for(int i = n-2; i>=0; i--){
        if(input[i] <= mini){
            mini = min(mini, input[i]);
            continue;
        }
        int k = input[i]/mini;
        if(input[i] % mini != 0) k++;
        ans += k-1;
        mini = input[i] / k;
    }


    cout<<ans<<endl;

    //cout<<f(21,3).first<<" "<<f(21,3).second;
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

