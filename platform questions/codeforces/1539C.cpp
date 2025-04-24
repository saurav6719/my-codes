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
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end());

    vector<int> diff;

    for(int i = 0; i<n-1; i++){
        if((input[i+1] - input[i]) <=x) continue;
        else {
            diff.push_back((input[i+1] - input[i]));
        }
    }
    sort(diff.begin() , diff.end());
    int i = 0;
    int ans =1;
    print(diff);
    while(i<diff.size()){
        int gap = diff[i];
        int req = gap/x;
        req--;
        if(gap % x != 0) req++;
        i++;
        if(k>=req) k-= req;
        else ans++;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

