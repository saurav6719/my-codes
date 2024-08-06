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

int f(double num) {
    return static_cast<int>(log(num) / log(3));
}

vector<int> powerr(55);

vector<int> dp(2e5+5);
void solve(){
    int l,r;
    cin>>l>>r;

    int ans = 0;
    int xx = dp[l];
    debug(xx);
    xx++;
    ans += xx;
    int xx2 = (l+1) * powerr[xx];
    
    debug(xx2);
    if(xx2 <= 2e5){
        ans += dp[xx2];
    }
    else ans += f(xx2);
    ans ++;
    debug(ans);

    int yy = l+2;

    while(yy <= r){
        debug(yy);
        int a;
        if(yy <= 2e5){
            a = dp[yy];
        }
        else a = f(yy);
        
        debug(a);
        int next = powerr[a+1];
        debug(next);
        if(next <= r){
            ans += ((a+1) * (next - yy));
            debug(ans); 
        }
        else{
            debug(r-yy+1);
            ans += ((r - yy + 1) * (a+1));
            break;
        }
        yy = next;
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

    for(int i = 1; i<=2e5; i++){
        dp[i] = f(i);
    }
    int curr = 1;
    for(int i = 0; i<50; i++){
        powerr[i] = curr;
        curr *= 3;
    }
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

