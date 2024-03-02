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
        string a1,a2;
        cin>>a1>>a2;    
        string ans = "";
        int down = n-1;
        int nod = -1;
        int i = 1;
        int j = 0;
        ans += a1[0];
        while(i<n and j<n){
            if(a1[i] == a2[j]) {
                ans += a1[i];
                i++;
                j++;
            }
            else if(a1[i] == '0' and a2[j] == '1'){
                ans += a1[i];
                i++;
                j++;
            }
            else {
                ans += a2[j];
                down = j+1;
                nod = 1;
                break;
            }
        }
        int d ;
        if(nod == 1){
            d = down - 1;
        }
        else d = n-1;
        debug(d);

    
        if(nod == 1){
            while(down <= n-1){
            ans += a2[down];
            down++;
            }
        }
        else ans+= a2[n-1];

        cout<<ans<<endl;
        int cnt = 1;
        
        while(d>0){
            if(a1[d] == a2[d-1]) {
                cnt++;
                d--;
            }
            else break;
        }
        
        cout<<cnt<<endl;
    
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

