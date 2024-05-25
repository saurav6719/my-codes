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
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> checking(n,-1);
    for(int i = 0; i<n; i++){
        bool check = false;
        if((i-1>= 0) and (input[i-1] >= input[i])){
            check = true;
        }
        if((i-2 >= 0) and (input[i-2] >= input[i])){
            check = true;
        }

        if((i+1 < n ) and (input[i+1] >= input[i])){
            check = true;
        }
        if((i+2 < n) and (input[i+2] >= input[i])){
            check = true;
        }

        if(check){
            checking[i] = 1;
        }
        else checking[i] = 0;
    }

    print(checking);

    int ans = INT_MIN;
    for(int i = 0; i<n; i++){
        if(checking[i] == 1){
            ans = max(ans, input[i]);
        }
    }

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

