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
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    int idx = -1;
    vector<int> prf(40, 0);

    for(int i = 0; i<40; i++){
        if(i==0) {
            prf[i] = 1;
            continue;
        }
        prf[i] = ((1<<i) + prf[i-1]);
    }

    //print(prf);


    for(int i = 1; i<n; i++){
        if(input[i] < input[i-1]){
            idx = i;
            break;
        }
    }

    if(idx==-1){
        cout<<0<<endl;
        return;
    }
    int ans = INT_MIN;
    while(idx < n){
        if(input[idx] >= input[idx-1]){
            idx++;
            continue;
        }
        int diff = abs(input[idx] - input[idx - 1]);
        int curr = lower_bound(prf.begin(), prf.end(), diff) - prf.begin();
        debug(curr);
        ans = max(ans, curr+1);
        input[idx] = input[idx-1];
        idx++;
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

