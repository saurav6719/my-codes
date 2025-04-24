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
    int n,m;
    cin>>n>>m;
    int n_copy = n;
    int m_copy = m;
    int cnt2 = 0;
    int cnt5 = 0;
    while(n_copy and n_copy % 2 == 0){
        n_copy /= 2;
        cnt2++;
    }
    while(n_copy and n_copy % 5 == 0){
        n_copy /= 5;
        cnt5++;
    }
    // debug(cnt2);
    // debug(cnt5);
    int ans =1 ;
    while(cnt5 > cnt2){
        if(m / 2 > 0 and m>0 ){ 
            ans*=2;
            m/=2;
            cnt2++;
        }
        else break;
    }
    while(cnt2 > cnt5){
        if(m / 5 > 0 and m>0 ){ 
            ans*=5;
            m/=5;
            cnt5++;
        }
        else break;
    }

    if(cnt2 == cnt5){
        while(m/10 >0 and m>0){
            ans *= 10;
            m/=10;
        }
    }

    ans *= (m_copy / ans);

    cout<<n*ans<<endl;

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

