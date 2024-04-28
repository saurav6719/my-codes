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
bool poss(int mid, vector<int> &input, int n, int h){
    vector<int> ne;
    for(int i = 0; i<mid; i++){
        ne.push_back(input[i]);
    }
    sort(ne.begin(), ne.end(), greater<int> ());
    int cnt = 0;
    for(int i = 0; i<ne.size(); i+=2){
        cnt+= ne[i];
    }
    if(cnt<=h) return true;
    return false;
}
void solve(){
    int n;
    cin>>n;
    int h;
    cin>>h;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int lo = 1;
    int hi = n;

    int res = -1;
    while(lo<=hi){
        int mid = (lo + hi )/2;
        debug(mid);
        if(poss(mid, input, n , h)){
            res = mid;
            lo = mid + 1 ;
        }
        else hi = mid - 1;
    }
    cout<<res;

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

