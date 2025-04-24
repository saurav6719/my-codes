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
    vector<int> input(n);
    set<int> st;
    for(int i = 0 ; i<n; i++){
      cin>>input[i];
      st.insert(input[i]);
    }
    if(st.size() == 1){
      cout<<"YES"<<endl;
      return;
    }

    int ans1 = 0;
    int ans2 = ans1;

    for(int i = 0; i<n; i++){
      ans2 ^= input[i];
    }

    for(int i = 0; i<n; i++){
      ans1 ^= input[i];
      ans2 ^= input[i];

      if(ans1 == ans2){
        cout<<"YES"<<endl;
        return;
      }
    }

    vector<int> prfxor(n+1);
    prfxor[0] = 0;
    for(int i = 0; i<n; i++){
      prfxor[i+1] = prfxor[i] ^ input[i];
    }
    print(prfxor);

    for(int i = 1; i<=n; i++){
      for(int j = i+1; j<=n; j++){

        int xor1 = prfxor[i] ^ prfxor[0];
        int xor2 = prfxor[j] ^ prfxor[i];
        int xor3 = prfxor[n] ^ prfxor[j];

        if(xor1 == xor2 and xor2 == xor3){
          cout<<"YES"<<endl;
          return;
        }
      }
    }

    cout<<"NO"<<endl;


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

