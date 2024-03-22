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
    int n,x;
    cin>>n>>x;
    vector<vector<int> > input(3, vector<int> (n));
    for(int i = 0; i<3; i++){
        for(int j = 0; j<n; j++){
            cin>>input[i][j];
        }
    }
    vector<int> ans;
    for(int i = 0; i<3; i++){
       // debug(i);
        bool flagk = false;
        for(int j = 0; j<n; j++){
            //debug(j);
            if(flagk) break;
            for(int k = 0; k<=32; k++){
                //debug(k);
                if((((input[i][j]) & (1<<k)) != 0) and ((x & (1<<k)) == 0)){
                    debug(input[i][j]);
                    flagk = true;
                    break;
                }
            }
            if(!flagk)ans.push_back(input[i][j]);
        }
    }
    print(ans);

    int answer = 0;
    for(int i = 0; i<ans.size(); i++){
        answer |= ans[i];
    }
    if(answer == x) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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

