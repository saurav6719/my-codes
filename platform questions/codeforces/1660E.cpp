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
int n;

void solve(){

    cin>>n;
    int ones = 0;
    vector<vector<int> > input(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){

            char ch;
            cin>>ch;
            if(ch == '1') input[i][j] =1;
            else input[i][j] =0;
            if(input[i][j] == 1) ones++;
        }
    }

    vector<vector<int>> dp(n, vector<int> (n));

    for(int j = n-1; j>=0; j--){
        int i = n-1;
        int curr =0;
        for(int k= 0; k<n; k++){
            if(input[i][j] == 1) curr++;
            i++;
            j++;
            i%=n;
            j%=n;
        }

        dp[i][j] = curr;
    }



    for(int i= n-2; i>=0;i--){
        for(int j = n-1; j>=0; j--){
            int ans = 0;
            int nexti = i+1;
            nexti %= n;
            int nextj = j+1;
            nextj %= n;
            ans += dp[nexti][nextj];
            dp[i][j] = ans;
        }
    }
    print2d(dp);

    int maxi =INT_MIN;

    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            maxi = max(maxi , dp[i][j]);
        }
    }

    int res = 0;

    ones -= maxi;
    res += ones;

    res += (n-maxi);

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
    // t = 1;
    while(t--){
        solve();
    }
return 0;
}

