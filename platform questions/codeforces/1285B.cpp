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
    int t_sum  =0;
    for(int i =0; i<n; i++){
        cin>>input[i];
        t_sum += input[i];
    }

    debug(t_sum);

    int idx1;
    int idx2 = 0;
    int maxi = INT_MIN;
    int sum = 0;
    for(int i =0; i<n; i++){
        sum += input[i];
        if(sum <= 0) {
            sum = 0;
            idx2 = i+1;
        }
        if(sum > maxi){
            maxi = sum;
            idx1 = i;
        }
    }
    debug(maxi);
    debug(idx1);
    debug(idx2);

    if(maxi > t_sum){
        cout<<"NO"<<endl;
        return;
    }

    if(maxi == t_sum){
        if(idx1 != n-1 or idx2 != 0){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;

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

