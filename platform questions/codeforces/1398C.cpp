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
    string str;
    cin>>str;
    for(int i = 0; i<n; i++){
        input[i] = str[i] - '0';
    }

    vector<int> prf(n);
    prf[0] = input[0];
    for(int i = 1; i<n; i++){
        prf[i] = input[i] + prf[i-1];
    }
    print(prf);
    int ans = 0;
    map<int,int> mp;

    for(int i = 0; i<n; i++){
        if(i==0){
            mp[1]++;
        }
        else{
            mp[prf[i-1] - i + 1]++;
        }

        int yy = prf[i] - i;
        ans += mp[yy];
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

