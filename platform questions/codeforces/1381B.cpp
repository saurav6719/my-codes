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
vector<vector<int> > dp;
bool f(vector<int> &arr, int x, int i){

    if(i==arr.size()){
        if(x==0) return true;
        return false;
    }

    if(x<0) return false;
    if(x==0) return true;

    if(dp[i][x] != -1) return dp[i][x];
    // pick 
    bool xx = f(arr, x-arr[i] , i+1);
    if(xx) return dp[i][x] = true;

    // not pick 

    bool yy = f(arr, x, i+1);
    if(yy) return dp[i][x] = true;
    return dp[i][x] = false;
}
void solve(){
    int n;
    cin>>n;
    vector<int> input(2*n);

    map<int,int> mp;
    for(int i = 0; i<2*n; i++){
        cin>>input[i];
        mp[input[i]] = i+1;
    }
    vector<int> arr;
    int curr = 2*n;
    dp.clear();
    dp.resize((2*n)+1, vector<int> ((2*n)+1, -1));

    for(int i = 2*n; i>=1; i--){
        int xx = mp[i];
        if(xx > curr) continue;
        int len = curr - xx + 1;
        arr.push_back(len);
        curr = xx-1;
    }

    print(arr);

    bool xx =f(arr, n, 0);
    if(xx) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;




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

