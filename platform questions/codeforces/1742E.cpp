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
    int k;
    cin>>n>>k;
    vector<int> input(n);
    vector<int> queries(k);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    for(int i = 0 ; i<k ;i++){
        cin>>queries[i];
    }
    
    vector<int> prfx(n);
    prfx[0] = input[0];
    for(int i = 1; i<n; i++){
        prfx[i] = prfx[i-1] + input[i];
    }

    vector<int> cmx(n);
    cmx[0] = input[0];
    for(int i = 1; i<n; i++){
        cmx[i] = max(input[i], cmx[i-1]); //sorted
    }

    //print(cmx);

    for(int i = 0; i<k ;i++){
        int h = queries[i];
        int xx = upper_bound(cmx.begin(), cmx.end(), h) - cmx.begin();
        
        xx--;
        //debug(xx);
        if(xx == -1){
            cout<<0<<" ";
            continue;
        }
        cout<<prfx[xx]<<" ";
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

