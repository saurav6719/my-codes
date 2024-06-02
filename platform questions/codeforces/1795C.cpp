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
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    vector<int> prf(n+1);
    prf[0] = 0;
    for(int i = 1; i<=n; i++){
        prf[i] = prf[i-1] + b[i-1];
    }

    vector<int> ans (n+1,0);

    vector<pair<int,int> > queries;
    print(prf);

    for(int i = 1; i<=n; i++){
        int ele = a[i-1];
        ele += prf[i-1];

        int xx = lower_bound(prf.begin(), prf.end(), ele) - prf.begin();
        debug(xx);

        if(xx <= n){
            ans[xx] += (a[i-1] - (prf[xx-1] - prf[i-1]));
            xx--;
            queries.push_back({i,xx});
        }
        else{
            xx--;
            queries.push_back({i,xx});
        }
    }

    print(ans);
    // for(auto ele : queries){
    //     cout<<ele.first<<" "<<ele.second<<endl;
    // }

    // for(auto ele : queries){
    //     if(ele.first > ele.second) continue;
    //     for(int i = ele.first; i<=ele.second; i++){
    //         ans[i] += b[i-1];
    //     }
    // }

    //print(ans);

    vector<int> res(n+1, 0);

    for(auto ele : queries){
        if(ele.first > ele.second) continue;
        res[ele.first]++;
        if(ele.second + 1 <=n) res[ele.second+1]--;
    }

    for(int i = 1; i<=n; i++){
        res[i] += res[i-1];
    }

    for(int i = 1; i<=n; i++){
        res[i] *= b[i-1];
    }

    for(int i= 1; i<=n; i++){
        res[i] += ans[i];
    }

    for(int i = 1; i<n+1; i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

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

