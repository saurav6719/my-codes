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

const long double EPSILON = 1e-9;
struct target{
    int x;
    int y;
    int timeofappearance;
    long double probabilityofhit;
};
vector<target> targets;

int timegap(int idx1, int idx2){
    return abs(targets[idx1].timeofappearance - targets[idx2].timeofappearance);
}

long double distance(int idx1, int idx2){
    return sqrtl((targets[idx1].x - targets[idx2].x)*(targets[idx1].x - targets[idx2].x) + (targets[idx1].y - targets[idx2].y)*(targets[idx1].y - targets[idx2].y));
}

long double dp[1001][1001];

long double f(int idx, int lasthit){


    debug(idx);
    debug(lasthit);

    if(idx == targets.size()){
        return 0;
    }

    if(fabsl(dp[idx][lasthit] + 1) > EPSILON) return dp[idx][lasthit];

    // cout<<"YEA"<<endl;


    long double ans = 0;

    //not hit it 

    ans = f(idx + 1 , lasthit);


    //hit it

    if(lasthit == targets.size()){
        ans = max(ans , f(idx+1 , idx ) + targets[idx].probabilityofhit);
    }
    else if (timegap(lasthit, idx) >= distance(lasthit, idx)){
        ans = max(ans , f(idx+1 , idx ) + targets[idx].probabilityofhit);
    }

    return dp[idx][lasthit] = ans;


}


void solve(){

    int n;

    cin>>n;
    targets.resize(n);
    for(int i=0;i<n;i++){
        cin>>targets[i].x>>targets[i].y>>targets[i].timeofappearance>>targets[i].probabilityofhit;
    }

    sort(targets.begin(), targets.end(), [](target a, target b){
        return a.timeofappearance < b.timeofappearance;
    });


    memset(dp, -1, sizeof dp);

    cout<<fixed<<setprecision(10)<<f(0, n)<<endl;





}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

