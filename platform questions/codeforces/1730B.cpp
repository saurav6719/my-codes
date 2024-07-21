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
double ans;
double currtime;

bool poss(double mid, vector<int> &x, vector<int> &t){
    double a = INT_MIN;
    double b = INT_MAX;
    int n = x.size();
    for(int i = 0; i<n; i++){
        if(mid < t[i]) return false;
        double rem = mid - t[i];
        a = max(a, x[i] - rem);
        b = min(b, x[i] + rem); 
    }

    if(a > b) return false;
    else{
        if(mid < currtime){
            ans = a;
        }
    }
    return true;


}
void solve(){
    ans = 0;
    currtime = INT_MAX;
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> t(n);
    for(int i = 0; i<n;i++){
        cin>>x[i];
    }

    for(int i = 0; i<n; i++){
        cin>>t[i];
    }

    double lo = 0;
    double hi = 2e8;

    int cnt = 0;

    while(hi - lo >1e-6){
        double mid = (lo + hi)/2;
        if(poss(mid, x, t)){
            hi = mid;
        }
        else lo = mid;
        cnt++;
    }

    cout << fixed << setprecision(10)<<ans<<endl;

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
    ///t = 1;
    while(t--){
        solve();
    }
return 0;
}

