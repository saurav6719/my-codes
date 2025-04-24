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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    map<int,int> mpb;
    map<int,int> mpa;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<int> b(m);
    for(int i = 0; i<m; i++){
        cin>>b[i];
        mpb[b[i]]++;
    }
    int ans = 0;
    int cnt = 0;
    for(int i= 0; i<m; i++){
        mpa[a[i]]++;
        int ele = a[i];
        if(mpa[ele] <= mpb[ele]) cnt++;
    }
    if(cnt >= k) ans++;

    int i = 0;
    int j = m;
    while(j<n){
        int ele = a[i];
        mpa[ele]--;
        if(mpa[ele] < mpb[ele])  cnt--;
        int ele2 = a[j];
        mpa[ele2]++;
        if(mpa[ele2] <= mpb[ele2]) cnt++;

        if(cnt>=k) ans++;
        i++;j++;
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

