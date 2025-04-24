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
    vector<int> b(n+1);

    vector<int> con;
   
    for(int i = 0; i<n; i++){
        cin>>a[i];
        con.push_back(a[i]);
    }
    for(int i = 0; i<=n; i++){
        cin>>b[i];
        if(i<n) con.push_back(b[i]);
    }


    int last = b[n];
    bool check = false;
    for(int i = 0; i<n; i++){
        if(a[i] >= last and b[i] <= last) check = true;
        if(a[i] <= last and b[i] >= last) check = true;
    }

    int ans = 0;
    for(int i = 0;i<n; i++){
        ans += abs(a[i] - b[i]);
    }
    if(check){
        ans++;
        cout<<ans<<endl;
        return;
    }
    int mini = INT_MAX;
    for(int i = 0; i<con.size(); i++){
        mini = min(mini, abs(con[i] - last));
    }

    ans += mini;
    ans++;
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

