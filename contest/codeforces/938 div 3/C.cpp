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
    int k;
    cin>>n>>k;
    int sum  =0;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
        sum += input[i];
    }
    int ff,ss;

    if(k&1){
        ff = (k+1)/2;
        ss = k/2;
    }
    else {
        ff = k/2;
        ss = k/2;
    }

    debug(ff);
    debug(ss);
    vector<int> prfl(n);
    prfl[0] = input[0];
    for(int i = 1;i<n; i++){
        prfl[i] = prfl[i-1] + input[i];
    }

    if(prfl[n-1] <= k){
        cout<<n<<endl;
        return;
    }

    vector<int> prfr(n);
    prfr[n-1] = input[n-1];
    for(int i = n-2; i>=0; i--){
        prfr[i] = prfr[i+1] + input[i];
    }

    print(prfl);
    reverse(prfr.begin(), prfr.end());
    print(prfr);
    

    int xx = -1;
    int yy = -1;
    for(int i = 0; i<n; i++){
        if(prfl[i] > ff){
            xx = i;
            break;
        }
    }
    for(int i = 0; i<n; i++){
        if(prfr[i] > ss){
            yy = i;
            break;
        }
    }

    debug(xx);
    debug(yy);

    int ans = xx+yy;
    if(ans >= n) ans = n;
    if(ans<=0) ans = 0;

    cout<<ans<<endl;
    return;
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

