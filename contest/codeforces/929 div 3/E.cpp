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
int cal(int u , int sec){
  int sum = 0;
  int f = u*(u+1)/2;
  int s = u-sec;
  int f1 = s*(s+1)/2;
  if(u>=sec){
    sum = f-f1;
  }
  else{
    int s1 = sec-u;
    s1--;
    int f2 = s1*(s1+1)/2;
    sum = f-f2;
  }
  return sum;
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
      cin>>input[i];
    }
    int q;
    cin>>q;
    vector<int> prfx(n+1,0);
    
    map<int,int> mp;
    for(int i = 1; i<=n; i++){
      prfx[i] = prfx[i-1]+input[i-1];
      mp[prfx[i]] = i;
    }
    //print(prfx);
    while(q--){
      int l;
      int u;
      cin>>l>>u;
      int ans ;
      int x = prfx[l-1] + u;
      // debug(x);
      int y = lower_bound(prfx.begin(), prfx.end(), x)- prfx.begin();
      // debug(y);
      int sec1 = y;
      int sec2 = y-1;
      int x1 = prfx[sec1] - prfx[l-1];
      int x2 = prfx[sec2] - prfx[l-1];
      int aa = cal(u,x1);
      int bb = cal(u,x2);
      if(mp[x]> 0){
        ans = mp[x];
        goto print;
      }
      if(sec1 > n){
        ans = n;
        goto print;
      }
      //  debug(x1);
      //  debug(x2);
      
      //  debug(aa);
      //  debug(bb);
      if(aa>bb){
        ans = y;
        goto print;
      }
      else{
        ans = y-1;
        goto print;
      }
      print :
      if(ans<l) ans = l;
      cout<<ans<<" ";
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

