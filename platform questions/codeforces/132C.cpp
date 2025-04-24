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
int maxi = 0;

int dp[101][51][205][2];
int f(int i, int k, int currans, bool forward, string &str){

    // debug(i);
    // debug(k);
    // debug(currans);
    // debug(forward);
    //base case

    if(k<0) return INT_MIN;
    if(i == str.size() and k!= 0) return INT_MIN;
    if(i==str.size() and k == 0) {
        maxi = max(maxi, abs(100-currans));

        return currans;
    }

    if(dp[i][k][currans][forward] != -1) return dp[i][k][currans][forward];

    int ans = INT_MIN;

    if(str[i] == 'F' and forward){
        //change

        ans = max(ans ,f(i+1, k-1, currans , false, str));

        // not change 
        ans = max(ans , f(i+1 , k, currans +1 , true, str));
    }

    if(str[i] == 'F' and forward == false){
        //change
        ans = max(ans ,f(i+1, k-1, currans , true, str));

        // not change 
        ans = max(ans , f(i+1 , k, currans  - 1 , false, str));

    }

    if(str[i] == 'T' and forward){
        //change 

        ans = max(ans , f(i+1, k-1, currans+1, true , str));

        //not change 

        ans = max(ans , f(i+1, k, currans , false, str));
    }

    if(str[i] == 'T' and !forward){
        ans = max(ans , f(i+1, k-1, currans - 1, false, str));

        ans = max(ans , f(i+1, k, currans, true, str));
    }

    return dp[i][k][currans][forward] = ans;
}
void solve(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    debug(str.size());
    memset(dp, -1, sizeof dp);
    int tc = 0;
    for(auto ele : str){
        if(ele == 'T') tc++;
    }

    if(k >= tc){
        for(auto & ele : str){
            if(ele == 'T') {
                ele = 'F';
                k--;
            }
        }
        k%=2;
    }

    

    int xx = f(0, k, 100, 1, str);
    cout<<maxi<<endl;
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

