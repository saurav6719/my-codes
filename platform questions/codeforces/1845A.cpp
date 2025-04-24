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
    int n,k,x;
    cin>>n>>k>>x;
    if(x != 1){
        // always possible
        cout<<"YES"<<endl;
        cout<<n<<endl;
        for(int i = 0; i<n; i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }



    if(k==1 and x==1){
        cout<<"NO"<<endl;
        return;
    }



    if(k==2 and x == 1){
        if(n%2 == 0){
            cout<<"YES"<<endl;
            cout<<n/2<<endl;
            for(int i = 0; i<n/2; i++){
                cout<<2<<" ";
            }
            cout<<endl;
            return;
        }
        else {
            cout<<"NO"<<endl;
            return;
        }
    }

    
    cout<<"YES"<<endl;
    if(n%2 == 0){
        cout<<n/2<<endl;
        for(int i  = 0; i<n/2; i++){
            cout<<2<<" ";
        }
        cout<<endl;
        return;
    }
    int n_copy = n-3;
    cout<<n_copy/2 + 1<<endl;
    for(int i = 0; i<n_copy/2; i++){
        cout<<2<<" ";
    }
    cout<<3;
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

