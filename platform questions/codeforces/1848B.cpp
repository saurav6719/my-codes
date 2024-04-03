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
bool poss(int mid , vector<int> &input){
    map<int,int> curr;
    int start  =  - 1;
    while ((start + mid + 1) < input.size()){
        start += (mid + 1);
        debug(input[start]);
        curr[input[start]]++;
    }
    debug(curr.size());
    if(curr.size() < 2) return true;
    if(curr.size() > 2) return false;
    else{
        int cnt = 0;
        for(auto ele : curr){
            if(ele.second > 1) cnt++;
        }
        if(cnt == 2) return false;
        return true;
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int lo = 0;
    int hi = n;
    int result = -1;
    while(lo <= hi){
        debug(lo);
        debug(hi);
        int mid = lo + (hi - lo)/2;
        if(poss(mid, input)) {
            debug(mid);
            result = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout<<result<<endl;
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

