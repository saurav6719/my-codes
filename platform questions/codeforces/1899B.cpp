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
    int res = 0;
    vector<int> factor;
    vector<int> input(n);
    for(int i = 0;i<n; i++){
        cin>> input[i];
    }
    vector<int> prf(n);
    prf[0] = input[0];
    for(int i = 1; i<n; i++){
        prf[i] = prf[i-1]+ input[i];
    }
    for(int i = 1; i*i<=n; i++){
        if(n%i == 0){
            factor.push_back(i);
            if(i != n/i) factor.push_back(n/i);
        }
    }
    print(prf);
    print(factor);

    for(int i = 0; i<factor.size(); i++){
        int sum1 = INT_MIN;
        int sum2 = INT_MAX;
        int a = 0;
        int b = factor[i]-1;
        //debug(factor[i]);
        while(b<n and a<n){
            // debug(sum1);
            // debug(sum2);
            if(a==0){
                sum1 = prf[b];
                sum2 = prf[b];
                a+= factor[i];
                b+= factor[i];
                continue;
            }
            sum1 = max(sum1, prf[b] - prf[a-1]);
            sum2 = min(sum2, prf[b] - prf[a-1]);
            res = max(res , abs(sum2- sum1));
            a+= factor[i];
            b+= factor[i];
        }
    }
    cout<<res<<endl;


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

