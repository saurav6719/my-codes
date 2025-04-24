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
bool poss(int mid, vector<int> &a, vector<int> &b){

    int curr = 0;

    int n = a.size();
    int cnt = 0;
    for(int i=0; i<n; i++){
        int big = mid - curr - 1;
        int small = mid - big - 1;
        if(a[i] >= big and b[i] >= small ) {
            cnt++;
            curr ++;
        }

        if(cnt >= mid) return true;
    }

    return false;
}



void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin>>a[i]>>b[i];
    }
    int res = -1;
    int lo = 0;
    int hi = n;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        //debug(mid);

        if(poss(mid, a, b)){
            res = mid;
            lo = mid+1;

        }
        else{
            hi = mid-1;
        }
    }

    cout<<res<<endl;
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

