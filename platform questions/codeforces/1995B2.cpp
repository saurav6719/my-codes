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

void solvee(){
    int n,m;
    cin>>n>>m;
    vector<int> petals(n);
    for(int i = 0; i<n; i++){
        cin>>petals[i];
    }

    vector<int> quantity(n);
    for(int i = 0; i<n; i++){
        cin>>quantity[i];
    }

    cout<<n<<"-"<<m<<":";
    for(int i = 0; i<n; i++){
        cout<<petals[i]<<"-";
    }
    cout<<":";
    for(int i = 0; i<n; i++){
        cout<<quantity[i]<<"-";
    }
    cout<<endl;
}

int f(int coins , int petal1, int petal2, int quantity1, int quantity2 ){
    debug(coins);
    if(((petal1 * quantity1) + (petal2 * quantity2)) <= coins){
        return (petal1 * quantity1) + (petal2 * quantity2);
    }

    int smalltaken = min(quantity1, (coins / petal1));
    debug(smalltaken);
    int remainingcoin = coins - (smalltaken * petal1);

    int bigtaken = min(quantity2 , (remainingcoin / petal2));

    remainingcoin -= (bigtaken * petal2);
    debug(remainingcoin);
    debug(bigtaken);

    int ans = (smalltaken*petal1) + (bigtaken *petal2);
    if(remainingcoin > 0){
        int smallcanconvert = min(smalltaken , remainingcoin);
        int bigcanbecome = quantity2 - bigtaken;
        ans += min(smallcanconvert, bigcanbecome);
    }
    return ans;

}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> petals(n);
    for(int i = 0; i<n; i++){
        cin>>petals[i];
    }

    vector<int> quantity(n);
    for(int i = 0; i<n; i++){
        cin>>quantity[i];
    }

    vector<pp> flowers;
    for(int i = 0; i<n; i++){
        flowers.push_back({petals[i] , quantity[i]});
    }

    sort(flowers.begin(), flowers.end());

    int ans = 0;

    for(int i = 0; i<n-1; i++){
        int total = (flowers[i].first * flowers[i].second);
        if(total <= m){
            ans = max(ans , total);
        }
        else{
            int cantake = m / flowers[i].first;
            int petalstake = cantake * (flowers[i].first);
            ans = max(ans, petalstake);
        }
        if(flowers[i].first == flowers[i+1].first - 1){
            ans = max(ans, f(m, flowers[i].first, flowers[i+1].first, flowers[i].second, flowers[i+1].second));
            // ans = max(ans, f(m, flowers[i+1].first, flowers[i].first, flowers[i+1].second, flowers[i].second));
        }
    }

    int lastnum = (flowers[n-1].first * flowers[n-1].second);
    if(lastnum <= m){
        ans = max(ans, lastnum);
    }
    else{
        int cantake = (m / flowers[n-1].first);
        int petalstake = (cantake * (flowers[n-1].first));
        ans = max(ans, petalstake);
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
    for(int i = 1; i<=t; i++){
        solve();
    }
return 0;
}

