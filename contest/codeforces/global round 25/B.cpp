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
    int k;
    cin>>k;
    k--;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int myval = input[k];

    int fda = -1;
    for(int i = 0; i<n; i++){
        if(input[i] > myval){
            fda = i;
            break;
        }
    }
    debug(fda);
    int ans = INT_MIN;
    if(fda > k or fda == -1){
        swap(input[k], input[0]);
        int cnt = 0;
        for(int i = 0; i<n-1; i++){
            if(myval > input[i+1]){
                cnt++;
            }
            else break;
        }
        ans = cnt;
        cout<<ans<<endl;
        return;
    }

    //chota 

    // 2 option 
    // 
    else{

        vector<int> copy = input;
        swap(input[fda], input[k]);
        // debug(input[fda]);
        // debug(input[k]);
        swap(copy[k], copy[0]);
        int cnt = 0;
        for(int i = 0; i<n-1;i++){
            if(copy[i+1] < myval){
                cnt++;

            }
            else break;
        }

        int cnt2 = 0;
        int tstar = max(0ll,fda - 1);
        debug(tstar);
        for(int i = tstar; i<n; i++ ){
            debug(input[i]);
            if(input[i] == myval) continue;
            if(input[i] < myval) {
                cnt2++;
            }
            else break;
        }
        debug(cnt);
        debug(cnt2);
        ans = max(cnt,cnt2);
        cout<<ans<<endl;
        return;


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
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

