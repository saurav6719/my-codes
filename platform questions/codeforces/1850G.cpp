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
    vector<pair<int,int> > input(n);
    map<int,int> x;
    map<int,int> y;
    map<int,int> diff;
    map<int,int> sum;
    
    for(int i = 0; i<n; i++){
        cin>>input[i].first>>input[i].second;
        x[input[i].first]++;
        y[input[i].second]++;
        int df = (input[i].first) - (input[i].second);
        int sm = (input[i].first) + (input[i].second);
        diff[df]++;
        sum[sm]++;

    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        int xx = input[i].first;
        int yy = input[i].second;
        int df = (input[i].first) - (input[i].second);
        int sm = (input[i].first) + (input[i].second);

        if(x[xx] > 1) ans += x[xx] - 1;
        if(y[yy] > 1) ans += y[yy] - 1;
        if(diff[df] > 1) ans += diff[df] - 1;
        if(sum[sm] > 1) ans += sum[sm] - 1;
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

