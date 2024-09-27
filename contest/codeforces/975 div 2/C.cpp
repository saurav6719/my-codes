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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */

bool poss(int k, int rem, int sum, int req, int n,int mid){
    debug(mid);
        debug(req);

    debug(rem);
    debug(sum);
    
    if(rem<0){
        if(req - sum <=k) return true;
        return false;
    }
    else if(rem == 0) return true;
    else {
        int chahiye = rem % mid;
        if(chahiye != 0) chahiye = mid - chahiye;
        if(chahiye <= k) return true;
        return false;
    }

    return false;


}
void solve(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> input(n);

    int maxi = -5;
    int sum = 0;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        sum += input[i];
        maxi = max(maxi, input[i]);
    }

    int losize = 1;
    int hisize = n;
    int res = -1;
    
    for(int i = n; i>=1; i--) {
        int mid = i;
        int req = maxi * mid;
        int rem = sum - req;

        if(poss(k,rem,sum,req, n, mid)){
            res = mid;
            break;
        }
        else hisize = mid -1;
    }
    debug(res);
    if(res == -1) res = 1;
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

