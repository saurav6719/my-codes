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
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>b[i];
    }

    int m;
    cin>>m;
    vector<int> modi(m);
    for(int i = 0; i<m; i++){
        cin>>modi[i];
    }

    map<int,int> mp;

    for(int i = 0; i<n; i++){
        if(a[i] != b[i]){
            mp[b[i]]++;
        }
    }

    set<int> bnum;
    for(int i = 0; i<n; i++){
        bnum.insert(b[i]);
    }

    if(bnum.count(modi[m-1]) == 0){
        cout<<"NO"<<endl;
        return;
    }

    map<int,int> modimap;
    for(int i = 0; i<m; i++){
        modimap[modi[i]]++;
    }

    for(auto ele : mp){
        if(modimap[ele.first] < ele.second){
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

