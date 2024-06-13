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
    int q;
    cin>>q;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> changes(n);
    changes[0] = 0;
    for(int i = 1; i<n-1; i++){
        if(input[i-1] >= input[i] and input[i] >=input[i+1]){
            changes[i] = 1+ changes[i-1];
        }
        else{
            changes[i] = changes[i-1];
        }
    }


    changes[n-1] = changes[n-2];

    print(changes);


    while(q--){
        int l;
        int r;
        cin>>l>>r;
        l--;
        r--;
        if(r-l == 1) {
            cout<<2<<endl;
            continue;
        }
        if(r==l){
            cout<<1<<endl;
            continue;
        }

        cout<<(r-l+1) - changes[r-1] + changes[l]<<endl;
    }

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

