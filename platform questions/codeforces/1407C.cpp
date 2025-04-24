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
    int idx = -1;
    int a = 1;
    vector<int> ans(n+5, -1);
    for(int i = 1; i<=n; i++){
        while(ans[a] != -1){
            a++;
        }
        int b = a+1;
        while(ans[b] != -1) b++;
        int k1;
        int k2;

        if(b>n) break;

        cout<<"? "<<a<<" "<<b<<endl;
        cout<<flush;
        cin>>k1;
        
        cout<<"? "<< b <<" " <<a<<endl;
        cout<<flush;
        cin>>k2;
        
        if(k1 > k2){
            ans[a] = k1;
        }
        else{
            ans[b] = k2;
        }
    }

    set<int> st;
    for(int i =1; i<=n; i++){
        if(ans[i] != -1) st.insert(ans[i]);
        else idx = i;
    }

    for(int i = 1; i<=n; i++){
        if(st.count(i) ==0 ){
            ans[idx] = i;
            break; 
        }
    }

    cout<<"!";
    for(int i = 1; i<=n; i++){
        cout<<" "<<ans[i];
    }
    cout<<endl;
    cout<<flush;
    return ;
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

