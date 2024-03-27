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
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int aa = 0;
    int maxi ;
    int sum = 0;
    while(aa<a){
        sum += input[aa];
        aa++;
    }
    maxi = sum;
    int bb= 0;
    int start = 0;
    int d= a;
    int curr = d;
    while(aa<b){
        sum += input[aa];
        if(sum > maxi){
            maxi = sum;
            d = aa;
        }
        aa++;
    }
    curr = b;
    debug(curr);
    debug(start);
    debug(maxi);
    while(curr < n){
        // if(curr > d){
        //     sum = 0;
        //     int end = curr + a - 1;
        //     while(curr < end and curr < n){
        //         sum += input[curr];
        //         curr++;
        //     }
        //     if(sum > maxi){
        //         maxi = sum;
        //         start = end - a + 1;
        //     }
        //     while(end < b and end<n){
        //         sum += input[end];
        //         if(sum > maxi){
        //             maxi = sum;
        //             d= end;
        //         }
        //         end++;
        //     }
        //     continue;
        // }
        debug(curr);
        debug(b);
        sum -= input[start];
        bb++;
        debug(sum);
        if(sum > maxi){
            maxi = sum;
            start = curr - 1;
        }
        debug(start);
        sum += input[curr];
        if(sum > maxi){
            maxi = sum;
            d = curr;
        }
        debug(d);
        curr++;
    }
     cout<<maxi<<endl;

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

