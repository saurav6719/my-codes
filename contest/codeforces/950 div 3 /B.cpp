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
    int n,f,k;
    cin>>n>>f>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int fav = input[f-1];
    //debug(fav);

    sort(input.begin(), input.end(), greater<int> ());

    int big = -1;
    int small = n;

    for(int i = 0; i<n; i++){
        if(input[i] == fav){
            big = i;
            break;
        }
    }

    for(int i = 0; i<n; i++){
        if(input[i] < fav){
            small = i;
            break;
        }
    }
    // debug(big);
    // debug(small);
    if(k<= big){
        cout<<"NO"<<endl;
        return;
    }

    if(k>= small){
        cout<<"YES"<<endl;
        return;
    }

    cout<<"MAYBE"<<endl;





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

