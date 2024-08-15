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
void solve(){
    int n;cin>>n;
    int k;cin>>k;
    string str;
    cin>>str;
    map<char,int> mp;
    int curr = 0;
    for(char ch = 'A'; ch<='Z'; ch++){
        mp[ch] = curr;
        curr++;
    }

    vector<vector<int>> dp(n, vector<int> (k, INT_MAX));

    for(int i = 0; i<k; i++){
        char ch = str[n-1];
        if(i==mp[ch]){
            dp[n-1][i] = 0;
        }
        else dp[n-1][i] = 1;
    }

    map<int,char> mp2;
    for(auto ele : mp){
        mp2[ele.second] = ele.first;
    }

    print(dp[n-1]);

    string str_copy = str;

    vector<vector<int> > dp2(n, vector<int> (k, -1));

    for(int i = n-2; i>=0; i--){
        for(int j = 0; j<k; j++){
            char ch = str[i];
            if(j == mp[ch]){
                for(int l = 0; l<k; l++){
                    if(l==j) continue;
                    if(dp[i+1][l] < dp[i][j]){
                        dp[i][j] = dp[i+1][l];
                        dp2[i][j] = l;
                    }
                    // dp[i][j] = min(dp[i][j] , dp[i+1][l]);
                }
            }
            else{
                for(int l = 0; l<k; l++){
                    if(l==j) continue;
                    // if(i==4 and j==0){
                    //     debug(dp[i+1][l]);
                    //     debug(dp[i][j]);
                    // }

                    if(1+ dp[i+1][l] < dp[i][j]){
                        dp[i][j] = 1+ dp[i+1][l];
                        dp2[i][j] = l;
                    }
                    //dp[i][j] =  min(dp[i][j] , 1+dp[i+1][l]);
                }
            }
        }

        // for(int j = 0; j<k; j++){
        //     cout<<dp[i][j]<<" ";
        // }
        // cout<<endl;
    }

    int ans = INT_MAX;

    for(int i = 0; i<k; i++){
        ans = min(ans , dp[0][i]);
    }
    cout<<ans<<endl;

    vector<int> res;

    int curr2 = INT_MAX;
    int curridx = -1;

    for(int i = 0; i<k; i++){
        if(dp[0][i] < curr2){
            curr2 = dp[0][i];
            curridx = i;
        }
    }

    res.push_back(curridx);

    for(int i = 0; i<n-1; i++){
        res.push_back(dp2[i][curridx]);
        curridx = res.back();
    }

    string final = "";

    for(int i = 0; i<res.size(); i++){
        final += mp2[res[i]];
    }

    cout<<final<<endl;

    
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

