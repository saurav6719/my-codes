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
#define inf 1e18
using namespace std;

/* write core logic here */
void solve(){
    int n;
    int c;
    int m;

    cin>>n>>m>>c;
    vector<int> input (n+1);
    input[0] = 0;
    for(int i = 1; i<=n; i++){
        cin>>input[i];
    }

    int total = m+c;
    int j = 1;
    vector<int> diff(n+1);
    diff[n] = 0;
    for(int i = n-1; i>=0; i--){
        diff[i] = input[i+1] - input[i];
    }

    //print(diff);

    vector<int> last(n);
    for(int i = n-1; i>=0; i--){
        if(i!= n-1) last[i] = j * diff[i] + last[i+1];
        else last[i] = j * diff[i];
        j++;
    }

    int ans = inf;

    for(int i =0; i<n; i++){
        int curr = last[i] * c + input[i] * total;
        ans = min(ans, curr);
    }

    cout<<ans<<endl;




    //print(last);

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

